// Fill out your copyright notice in the Description page of Project Settings.


#include "Muro_Electrico.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

AMuro_Electrico::AMuro_Electrico()
{
	meshMuro_Electrico = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Muro_Electrico"));
	meshMuro_Electrico->SetSimulatePhysics(false);
	meshMuro_Electrico->SetupAttachment(RootComponent);
	RootComponent = meshMuro_Electrico;
	RootComponent->SetMobility(EComponentMobility::Movable);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroLadrilloAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MuroLadrilloAsset.Succeeded())
	{
		meshMuro_Electrico->SetStaticMesh(MuroLadrilloAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel'"));
	if (MaterialAsset.Succeeded())
	{
		meshMuro_Electrico->SetMaterial(0, MaterialAsset.Object);
	}

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Sparks.P_Sparks'"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
	}
	SetActorScale3D(FVector(2.0f, 0.25f, 2.0f));
}
// Called when the game starts or when spawned
void AMuro_Electrico::BeginPlay()
{
	Super::BeginPlay();

}

void AMuro_Electrico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
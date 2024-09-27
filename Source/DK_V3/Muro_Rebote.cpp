// Fill out your copyright notice in the Description page of Project Settings.


#include "Muro_Rebote.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

void AMuro_Rebote::BeginPlay()
{
	Super::BeginPlay();
}

AMuro_Rebote::AMuro_Rebote()
{
	meshMuro_Rebote = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Muro_Rebote"));
	meshMuro_Rebote->SetSimulatePhysics(false);
	meshMuro_Rebote->SetupAttachment(RootComponent);
	RootComponent = meshMuro_Rebote;
	RootComponent->SetMobility(EComponentMobility::Movable);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroResorteAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MuroResorteAsset.Succeeded())
	{
		meshMuro_Rebote->SetStaticMesh(MuroResorteAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'"));
	if (MaterialAsset.Succeeded())
	{
		meshMuro_Rebote->SetStaticMesh(MuroResorteAsset.Object);
	}

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
	}
	SetActorScale3D(FVector(2.0f, 0.25f, 2.0f));

}

void AMuro_Rebote::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMuro_Rebote::AplicarEfecto()
{
	GetWorldTimerManager().SetTimer(TimerHandle_DesactivarRebote, this, &AMuro_Rebote::DesactivarRebote, 3.0f, false);
	PrimaryActorTick.bCanEverTick = true;
}

void AMuro_Rebote::DesactivarRebote()
{
	//ParticleSystem->Deactivate();
	//meshMuroResorte->SetVisibility(false);
	PrimaryActorTick.bCanEverTick = false;
}
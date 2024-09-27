/*// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroLadrillo.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

AMuroLadrillo::AMuroLadrillo()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	MeshObstaculo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	MeshObstaculo->SetStaticMesh(MeshAsset.Object);
	RootComponent = MeshObstaculo;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroLadrilloAsset(TEXT("StaticMesh'/Game/Modelos3D/stone_wall_wall_stone.stone_wall_wall_stone'"));
	if (MuroLadrilloAsset.Succeeded())
	{
		meshMuroLadrillo->SetStaticMesh(MuroLadrilloAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));
	if (MaterialAsset.Succeeded())
	{
		meshMuroLadrillo->SetMaterial(0, MaterialAsset.Object);
	}

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleSystem->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	if (ParticleSystemAsset.Succeeded())
	{
		ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
	}

	SetActorScale3D(FVector(2.0f, 0.25f, 2.0f));
}

void AMuroLadrillo::BeginPlay()
{
	Super::BeginPlay();
}

void AMuroLadrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
*/
// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroLadrillo.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AMuroLadrillo::AMuroLadrillo()
{
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	ConstructorHelpers::FObjectFinder<UMaterial> material(TEXT("Material'/Game/StarterContent/Materials/M_Brick_Clay_Old.M_Brick_Clay_Old'"));
	meshMuroLadrillo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroMesh"));
	meshMuroLadrillo->SetStaticMesh(mesh.Object);
	RootComponent = meshMuroLadrillo;

	//posicionInicial = FVector(0.0f, 0.0f, 0.0f);
	//posicionActual = FVector(0.0f, 0.0f, 0.0f);
	//posicionFinal = FVector(0.0f, 0.0f, 0.0f);
	//incrementoZ = 2.0f;
	//bajando = true;
}

//void AMuroLadrillo::moverMuro()
//{
//}

void AMuroLadrillo::Tick(float DeltaTime)
{
	//if (bajando)
	//{
	//	posicionActual.Z -= incrementoZ;
	//	if (posicionActual.Z <= posicionFinal.Z)
	//	{
	//		bajando = false;
	//	}
	//}
	//else
	//{
	//	posicionActual.Z += incrementoZ;
	//	if (posicionActual.Z >= posicionInicial.Z)
	//	{
	//		bajando = true;
	//	}
	//}

	//SetActorLocation(posicionActual);
}

void AMuroLadrillo::BeginPlay()
{
	/*posicionInicial = GetActorLocation();
	posicionActual = posicionInicial;
	posicionFinal = posicionInicial + FVector(0.0f, 0.0f, 100.0f);*/
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentePlataforma.h"

// Sets default values
AComponentePlataforma::AComponentePlataforma()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));

	meshPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	meshPlataforma->SetStaticMesh(MeshAsset.Object);
	RootComponent = meshPlataforma;

	FVector NewScale(2.0f, 3.0f, 0.5f); // Cambia estos valores según tus necesidades
	SetActorScale3D(NewScale);

	DireccionMovimiento = FVector(0.0f, 0.0f, 1.0f); // Movimiento hacia arriba por defecto
	VelocidadMovimiento = 100.0f; // Velocidad por defecto

}

// Called when the game starts or when spawned
void AComponentePlataforma::BeginPlay()
{
	Super::BeginPlay();

	// Configurar el temporizador para invertir la dirección cada 2 segundos
	GetWorld()->GetTimerManager().SetTimer(InvertirDireccionTimerHandle, this, &AComponentePlataforma::InvertirDireccion, 2.0f, true);

}

// Called every frame
void AComponentePlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Actualizar la posición de la plataforma
	FVector NuevaPosicion = GetActorLocation() + (DireccionMovimiento * VelocidadMovimiento * DeltaTime);
	SetActorLocation(NuevaPosicion);

}
// Función para invertir la dirección del movimiento
void AComponentePlataforma::InvertirDireccion()
{
	DireccionMovimiento *= -1;
}
bool AComponentePlataforma::SetMovimientoHorizontal()
{
	return true;
}

bool AComponentePlataforma::SetMovimientoVertical()
{
	return true;
}
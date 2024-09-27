// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponenteMovil.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AComponenteMovil::AComponenteMovil()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	MeshMovil = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroMesh"));
	MeshMovil->SetStaticMesh(mesh.Object);
	RootComponent = MeshMovil;

	RangoMovimiento = 500.0f; // Establece el rango de movimiento
	bMoviendoDerecha = true;
	//ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	//MeshMovil = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	/*PosicionInicial = FVector(1200.0f, -1000.0f, 400.f);
	RotacionInicial = FRotator(0.0f, 0.0f, 10.0f);
	VelocidadMovimiento = 100.0f;*/

}

// Called when the game starts or when spawned
void AComponenteMovil::BeginPlay()
{
	Super::BeginPlay();
	UbicacionInicial = GetActorLocation();

}

// Called every frame
void AComponenteMovil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector UbicacionActual = GetActorLocation();
	if (bMoviendoDerecha)
	{
		UbicacionActual.Y += 100.0f * DeltaTime; // Mover a la derecha
		if (UbicacionActual.Y >= UbicacionInicial.Y + RangoMovimiento)
		{
			bMoviendoDerecha = false;
		}
	}
	else
	{
		UbicacionActual.Y -= 100.0f * DeltaTime; // Mover a la izquierda
		if (UbicacionActual.Y <= UbicacionInicial.Y - RangoMovimiento)
		{
			bMoviendoDerecha = true;
		}
	}
	SetActorLocation(UbicacionActual);

	//MoverComponente(DeltaTime);
	//FVector CurrentPosition = GetActorLocation();

}

/*void AComponenteMovil::MoverComponente(float DeltaTime)
{
	PosicionInicial.Y += VelocidadMovimiento * DeltaTime;
	SetActorLocation(PosicionInicial);
	SetActorRotation(RotacionInicial);
}*/


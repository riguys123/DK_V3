// Fill out your copyright notice in the Description page of Project Settings.

#include "Barril.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

// Sets default values
ABarril::ABarril()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> BarrilMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	BarrilMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BarrilMesh"));
	RootComponent = BarrilMesh;
	BarrilMesh->SetStaticMesh(BarrilMeshAsset.Object);
	//BarrilMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	//BarrilMesh->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));

	// Habilitar la simulación de física
	BarrilMesh->SetSimulatePhysics(true);
	BarrilMesh->SetMobility(EComponentMobility::Movable);

	// Configurar la colisión
	BarrilMesh->SetCollisionProfileName(TEXT("PhysicsActor"));
	//BarrilMesh->OnComponentBeginOverlap.AddDynamic(this, &ABarril::OnOverlapBegin);

	// Ajustar la masa del cilindro
	BarrilMesh->SetMassOverrideInKg(NAME_None, 100000.0f); // Ajusta el valor según sea necesario


}

// Called when the game starts or when spawned
void ABarril::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABarril::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarril::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//if (OtherActor && (OtherActor != this) && OtherComp)
	//{
	//	ACharacter* Character = Cast<ACharacter>(OtherActor);
	//	if (Character)
	//	{
	//		// Aplicar daño al personaje
	//		UGameplayStatics::ApplyDamage(Character, 10.0f, nullptr, this, nullptr);
	//	}
	//}
}
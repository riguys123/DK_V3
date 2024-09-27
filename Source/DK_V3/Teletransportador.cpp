#include "Teletransportador.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ATeletransportador::ATeletransportador()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
    MeshTeletransportador = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshTeletransportador"));
    MeshTeletransportador->SetStaticMesh(mesh.Object);
    RootComponent = MeshTeletransportador;

    // Bind the OnComponentBeginOverlap event to the function
    MeshTeletransportador->OnComponentBeginOverlap.AddDynamic(this, &ATeletransportador::OnMeshOverlap);
}

// Called when the game starts or when spawned
void ATeletransportador::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ATeletransportador::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Function called when the mesh overlaps with another object
/*void ATeletransportador::OnMeshOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    // Check if the overlapping actor is valid and is not the teleporter itself
    if (OtherActor && OtherActor != this)
    {
        // Teleport the overlapping actor to the target location
        OtherActor->SetActorLocation(TargetLocation);
    }
}*/
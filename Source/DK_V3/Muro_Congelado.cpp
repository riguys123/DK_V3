#include "Muro_Congelado.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

void AMuro_Congelado::BeginPlay()
{
    Super::BeginPlay();
}

AMuro_Congelado::AMuro_Congelado()
{
    meshMuro_Congelado = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroLadrillo"));
    meshMuro_Congelado->SetSimulatePhysics(false);
    meshMuro_Congelado->SetupAttachment(RootComponent);
    RootComponent = meshMuro_Congelado;
    RootComponent->SetMobility(EComponentMobility::Movable);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MuroLadrilloAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
    if (MuroLadrilloAsset.Succeeded())
    {
        meshMuro_Congelado->SetStaticMesh(MuroLadrilloAsset.Object);
    }

    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'"));
    if (MaterialAsset.Succeeded())
    {
        meshMuro_Congelado->SetStaticMesh(MuroLadrilloAsset.Object);
    }

    ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
    ParticleSystem->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Steam_Lit.P_Steam_Lit'"));
    if (ParticleSystemAsset.Succeeded())
    {
        ParticleSystem->SetTemplate(ParticleSystemAsset.Object);
    }
    SetActorScale3D(FVector(2.0f, 0.25f, 2.0f));

}

void AMuro_Congelado::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMuro_Congelado::AplicarEfecto()
{
    GetWorldTimerManager().SetTimer(TimerHandle_Congelacion, this, &AMuro_Congelado::Descongelar, 3.0f, false);
    PrimaryActorTick.bCanEverTick = true;
}

void AMuro_Congelado::Descongelar()
{
    //ParticleSystem->Deactivate();
    //meshMuroHielo->SetVisibility(false);
    PrimaryActorTick.bCanEverTick = false;
}
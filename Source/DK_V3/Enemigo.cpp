// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Proyectil.h"
#include "Components/SceneComponent.h"
#include "DK_V3Character.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AEnemigo::AEnemigo()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    UltimaPosicionMario = FVector::ZeroVector;
    bProyectilDisparado = false;
    IntervaloDisparo = 1.0f; // Establece el intervalo de disparo en 2 segundos

    ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));

    MeshMono = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MuroMesh"));
    MeshMono->SetStaticMesh(mesh.Object);
    RootComponent = MeshMono;

    RangoMovimiento = 600.0f; // Establece el rango de movimiento
    bMoviendoDerecha = true;


    //FireRate = 1.0f; // Establece la tasa de disparo en 2 segundos

}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
    Super::BeginPlay();

    UbicacionInicial = GetActorLocation();
    //const FRotator Rotation = FRotator(0.0f, 0.0f, 0.0f); configura el temporizador para disparar proyectiles (a intervalos regulares)
    FTimerHandle TimerHandle_Disparo;
    GetWorldTimerManager().SetTimer(TimerHandle_Disparo, this, &AEnemigo::ActualizarPosicionMario, IntervaloDisparo, true);
}
// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector UbicacionActual = GetActorLocation();
    if (bMoviendoDerecha)
    {
        UbicacionActual.Y += 500.0f * DeltaTime; // Mover a la derecha
        if (UbicacionActual.Y >= UbicacionInicial.Y + RangoMovimiento)
        {
            bMoviendoDerecha = false;

        }
    }
    else
    {
        UbicacionActual.Y -= 500.0f * DeltaTime; // Mover a la izquierda
        if (UbicacionActual.Y <= UbicacionInicial.Y - RangoMovimiento)
        {
            bMoviendoDerecha = true;

        }
    }
    SetActorLocation(UbicacionActual);
}

void AEnemigo::DispararProyectil(FVector Objetivo)
{
    if (Objetivo != FVector::ZeroVector)
    {
        FVector DireccionDisparo = (Objetivo - GetActorLocation()).GetSafeNormal();
        FRotator RotacionDisparo = DireccionDisparo.Rotation();
        FVector UbicacionDisparo = GetActorLocation() + FVector(0.f, 0.f, -50.f); // Ajusta la ubicación de disparo si es necesario

        UWorld* const World = GetWorld();
        if (World)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Disparando proyectil"));
            World->SpawnActor<AProyectil>(UbicacionDisparo, RotacionDisparo);
            AProyectil* Proyectil = World->SpawnActor<AProyectil>(UbicacionDisparo, RotacionDisparo);
            if (Proyectil)
            {
                Proyectil->SetDireccion(DireccionDisparo);
                bProyectilDisparado = true;
                GetWorldTimerManager().SetTimer(Temporizador_Disparo, this, &AEnemigo::ActualizarPosicionMario, IntervaloDisparo, true);
            }
        }
    }
}

void AEnemigo::ResetProyectilDisparo()
{

    bProyectilDisparado = false;
}


void AEnemigo::ActualizarPosicionMario()
{
    ADK_V3Character* Mario = Cast<ADK_V3Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (Mario)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Posición de Mario actualizada"));
        DispararProyectil(UltimaPosicionMario);
        UltimaPosicionMario = Mario->GetActorLocation();

    }

}




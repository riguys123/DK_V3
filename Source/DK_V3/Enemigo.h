// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

class UStaticMeshComponent;


UCLASS()
class DK_V3_API AEnemigo : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void DispararProyectil(FVector Objetivo);
	void ResetProyectilDisparo();
private:

	FTimerHandle Temporizador_Disparo;
	FVector UltimaPosicionMario;
	bool bProyectilDisparado;
	float IntervaloDisparo;
	void ActualizarPosicionMario();
	// Movement range
	UPROPERTY(EditAnywhere, Category = "Movement")
	float RangoMovimiento;

	// Initial location
	FVector UbicacionInicial;

	// Direction flag
	bool bMoviendoDerecha;

	// Mesh component
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* MeshMono;


};

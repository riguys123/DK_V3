// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComponenteMovil.generated.h"

class UStaticMeshComponent;

UCLASS()
class DK_V3_API AComponenteMovil : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AComponenteMovil();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UStaticMeshComponent* MeshMovil;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoverComponente(float DeltaTime);

private:

	FVector UbicacionInicial;
	float RangoMovimiento;
	bool bMoviendoDerecha;

};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComponentePlataforma.generated.h"

class UStaticMeshComponent;

UCLASS()
class DK_V3_API AComponentePlataforma : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AComponentePlataforma();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//PROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* meshPlataforma;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Dirección del movimiento
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
	FVector DireccionMovimiento;

	// Velocidad del movimiento
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
	float VelocidadMovimiento;
	float TiempoBajar;
	float TiempoSubir;
	float LimiteSuperior;
	float LimiteInferior;

	// Función para invertir la dirección del movimiento
	void InvertirDireccion();

	bool SetMovimientoHorizontal();


	bool SetMovimientoVertical();

private:
	// Temporizador para invertir la dirección
	FTimerHandle InvertirDireccionTimerHandle;
};
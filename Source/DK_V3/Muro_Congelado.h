// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MuroLadrillo.h"
#include "Muro_Congelado.generated.h"

class UParticleSystemComponent;
class UStaticMeshComponent;
/**
 *
 */
UCLASS()
class DK_V3_API AMuro_Congelado : public AMuroLadrillo
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	UParticleSystemComponent* ParticleSystem;
	UStaticMeshComponent* meshMuro_Congelado;


public:
	AMuro_Congelado();

public:
	virtual void Tick(float DeltaTime) override;
	virtual void AplicarEfecto() override;
private:
	FTimerHandle TimerHandle_Congelacion;

	void Descongelar();

};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MuroLadrillo.h"
#include "Muro_Electrico.generated.h"

    class UParticleSystemComponent;
	class UStaticMeshComponent;

/**
 *
 */
UCLASS()
class DK_V3_API AMuro_Electrico : public AMuroLadrillo
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	UParticleSystemComponent* ParticleSystem;
	UStaticMeshComponent* meshMuro_Electrico;


public:
	// Sets default values for this actor's properties
	AMuro_Electrico();

public:
	virtual void Tick(float DeltaTime) override;

};
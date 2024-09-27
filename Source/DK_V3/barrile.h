// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "barrile.generated.h"

UCLASS()
class DK_V3_API Abarrile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Abarrile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DK_V3GameMode.generated.h"

class AObstaculoMuro;
class AComponentePlataforma;
class ADK_V3Character;
class ABarril;
class AEsfera;
class AMuroLadrillo;


UCLASS(minimalapi)
class ADK_V3GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADK_V3GameMode();

	AObstaculoMuro* obstaculo01;
	ADK_V3Character* player01;
	AMuroLadrillo* muroLadrillo01;
	TArray<AComponentePlataforma*> ComponentesPlataforma;
	TArray<ABarril*> barriles;
	TMap<int32, AEsfera*> esferasMap;


protected:
	virtual void BeginPlay() override;


private:
	FTimerHandle SpawnBarrilTimerHandle;
	void SpawnBarril();

	int32 contadorBarriles;
	const int32 numeroMaximoBarriles = 3;

};




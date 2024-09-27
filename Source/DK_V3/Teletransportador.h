
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Teletransportador.generated.h"


class UStaticMeshComponent;

UCLASS()
class DK_V3_API ATeletransportador : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATeletransportador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UStaticMeshComponent* MeshTeletransportador;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnMeshOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
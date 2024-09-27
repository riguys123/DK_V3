// Fill out your copyright notice in the Description page of Project Settings.
/**
#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "MuroLadrillo.generated.h"


class UParticleSystemComponent;
class UStaticMeshComponent;
 *

UCLASS()
class DK_V3_API AMuroLadrillo : public AObstaculo
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UParticleSystemComponent* ParticleSystem;
	UStaticMeshComponent* meshMuroLadrillo;

public:
	AMuroLadrillo();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
 */
 //Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MuroLadrillo.generated.h"

class UStaticMeshComponent;

UCLASS()
class DK_V3_API AMuroLadrillo : public AActor
{

	GENERATED_BODY()


public:
	// Sets default values for this actor's properties
	AMuroLadrillo();

	//void desactivar();
	//void activar();
	//void mostrar();
	//void ocultar();
	//void movimiento(float value);

protected:
	UStaticMeshComponent* meshMuroLadrillo;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void AplicarEfecto() {};
	virtual void ManejarColision(AActor* OtherActor) PURE_VIRTUAL(AMuroLadrillo::ManejarColision, );
protected:
	bool subir;
	FVector posicionInicial;
	FVector posicionActual;
	FVector posicionFinal;
	float incrementoZ;
	bool detener;

public:
	FORCEINLINE UStaticMeshComponent* GetMeshMuroLadrillo() const { return meshMuroLadrillo; }
	FORCEINLINE void setIncrementoZ(float incremento) { incrementoZ = incremento; }
	FORCEINLINE void setDetener(bool _detener) { detener = _detener; }

};
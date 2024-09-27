// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DK_V3Character.generated.h"


class AObstaculo;

UCLASS(config = Game)
class ADK_V3Character : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

protected:

	/** Called for side to side input */

	void MoveRight(float Val);

	/** Handle touch inputs. */

	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */

	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface


	// End of APawn interface

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FVector GunOffset;
	FVector GetCurrentPosition() const;

	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void Parar();
	bool detener;

public:

	ADK_V3Character();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

protected:

	float FireRate;
	void FireShot(FVector _Direction);
	static const FName FireRightBinding;
	/* Handler for the fire timer expiry */
	void ShotTimerExpired();

	void FireRight(float Val);

	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void FireLeft(float Val);

	void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit);
	void ReanudarMovimiento();

	AObstaculo* obstaculo01;

public:
	/** Returns obstaculo01 subobject **/
	FORCEINLINE AObstaculo* GetObstaculo() const { return obstaculo01; }
	FORCEINLINE void SetObstaculo(AObstaculo* _obstaculo) { obstaculo01 = _obstaculo; }

private:
	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

};
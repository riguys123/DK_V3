// Copyright Epic Games, Inc. All Rights Reserved.

#include "DK_V3Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Proyectil.h"
#include "Obstaculo.h"	
//#include "MuroHielo.h"


const FName ADK_V3Character::FireRightBinding("FireRight");
//const FName ADonkeyKong_SIS457Character::FireLeftBinding("FireLeft");

ADK_V3Character::ADK_V3Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)


	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f, 0.f, 75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));

	// Create a camera and attach to boom


	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement


	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
	bCanFire = true;
	FireRate = 0.3f;
	GunOffset = FVector(0.f, 90.f, 0.f);

}

//////////////////////////////////////////////////////////////////////////
// Input

FVector ADK_V3Character::GetCurrentPosition() const
{
	return FVector();
}

void ADK_V3Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	//er::SetupPlayerInputComponent(PlayerInputComponent);

	// set up gameplay key bindings bgvvvvvvvvvvvvv
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &ADK_V3Character::MoveRight);
	//PlayerInputComponent->BindAction("Parar", IE_Pressed, this, &ADonkeyKong_L01Character::Parar);
	//PlayerInputComponent->BindAction("Parar", IE_Released, this, &ADonkeyKong_L01Character::Parar);
	PlayerInputComponent->BindAxis("FireRight", this, &ADK_V3Character::FireRight);
	PlayerInputComponent->BindAxis("FireLeft", this, &ADK_V3Character::FireLeft);
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ADK_V3Character::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ADK_V3Character::TouchStopped);

}

void ADK_V3Character::BeginPlay()
{
	// posicion de mario arriba 
	Super::BeginPlay(); 
	FVector StartLocation = FVector(1260.f, 1200.f, 4245.f);
	SetActorLocation(StartLocation);
}

void ADK_V3Character::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(0.f, FireRightValue, 0.f);

	// Try and fire a shot
	//FireShot(FireDirection);
}

void ADK_V3Character::Parar()
{
	//obstaculo01->setIncrementoZ(0.0f);
	detener = !detener;
	obstaculo01->setDetener(detener);
}


void ADK_V3Character::MoveRight(float Value)
{
	// add movement in that direction

	AddMovementInput(FVector(0.f, -1.f, 0.f), Value);
}

void ADK_V3Character::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	//Hace que el personaje salte al tocar la pantalla.
	Jump();
}

void ADK_V3Character::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	//Hace que el personaje deje de saltar cuando el toque en la pantalla se detiene.
	StopJumping();
}

void ADK_V3Character::FireShot(FVector _Direction)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (_Direction.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = _Direction.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AProyectil>(SpawnLocation + FVector(0.f, 20.f, 0.f), FireRotation);
			}
			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &ADK_V3Character::ShotTimerExpired, FireRate);

		}
	}
}

void ADK_V3Character::ShotTimerExpired()
{
	bCanFire = true;
}

void ADK_V3Character::FireRight(float Val)
{
	const FVector FireDirection = FVector(0.f, Val, 0.f);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("Derecha: %f"), Val));
	FireShot(FireDirection);
}

void ADK_V3Character::FireLeft(float Val)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Izquierda: %f"), Val));
	const FVector FireDirection = FVector(0.f, Val, 0.f);
	FireShot(FireDirection);
}

void ADK_V3Character::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	//// Verificar si el actor con el que colisionamos es un MuroHielo
	//if (Other->IsA(AMuroHielo::StaticClass()))
	//{
	//	// Detener el movimiento del personaje
	//	GetCharacterMovement()->DisableMovement();

	//	// Programar una funci�n para reanudar el movimiento despu�s de 2 segundos
	//	FTimerHandle TimerHandle;
	//	GetWorldTimerManager().SetTimer(TimerHandle, this, &ADK_V3Character::ReanudarMovimiento, 2.0f, false);
	//}
}

void ADK_V3Character::ReanudarMovimiento()
{
	// Reanudar el movimiento del personaje
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
}
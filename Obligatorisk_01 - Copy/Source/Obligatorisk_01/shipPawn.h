#pragma once

#include "GameFramework/Pawn.h"
#include "shipPawn.generated.h"

UCLASS()
class OBLIGATORISK_01_API AshipPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for Players's properties
	AshipPawn();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Set the Tick function to follow DeltaSeconds
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void Move_YAxis(float AxisValue);

	void Shoot();

	FVector CurrentVelocity;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class ABullet> Bullet_BP;

	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class AAlien> Alien_BP;


	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;

	UPROPERTY(EditAnywhere)
		AActor* CameraOne = nullptr;

	// Sets the max distance Aliens will spawn in X and Y axis
	const int max_Y = 1200;

	const int max_X = 150;

	// Defines how far spaced each alien is
	const int positionIncrement = 100;

};
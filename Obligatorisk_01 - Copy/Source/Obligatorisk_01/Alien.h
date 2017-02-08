#pragma once

#include "GameFramework/Actor.h"
#include "Alien.generated.h"

UCLASS()
class OBLIGATORISK_01_API AAlien : public AActor
{
	GENERATED_BODY()

public:
	// Constructor
	AAlien();

	// Function that starts when Aliens are spawned
	virtual void BeginPlay() override;

	// Function for Alien movement
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;

	// Defines the startspeed of the Aliens
	FVector CurrentVelocity = FVector(1.0f, 0.0f, 0.0f)*300.0f;


};

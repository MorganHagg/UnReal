// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class OBLIGATORISK_01_API ABullet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for Bullet
	ABullet();

	// Called when the Bullet is spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Make editable anywhere
	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;

	// Setting bullet speed
	FVector CurrentVelocity = FVector(1.0f, 0.0f, 0.0f)*100.0f;

	// Initialising for collision and overlap
	UShapeComponent* CollisionBox = nullptr;

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
};
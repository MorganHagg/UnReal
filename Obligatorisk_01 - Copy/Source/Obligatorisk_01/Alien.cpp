#pragma once 

#include "Obligatorisk_01.h"
#include "Alien.h"


// Sets default values to Alien
AAlien::AAlien()
{
	// Set the Tick funciton to be called every frame
	PrimaryActorTick.bCanEverTick = true;

	// Defines the hitbox of Aliens
	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));

	// Defines the visible component of the hitbox
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

}

// Called when Aliens are spawned
void AAlien::BeginPlay()
{
	Super::BeginPlay();

}

// Creates movement for Aliens
void AAlien::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation() - (CurrentVelocity * DeltaTime);
	SetActorLocation(NewLocation);

	FVector Hit = GetActorLocation();


	// Defines how far down the Aliens can go
	if (Hit.X <= -1100.0f)
	{
		CurrentVelocity = FVector(-1.0f, 0.0f, 0.0f)*300.0f;
	}

	// Defines how far up the Aliens can go
	if (Hit.X >= 300.0f)
	{
		CurrentVelocity = FVector(1.0f, 0.0f, 0.0f)*300.0f;
	}
}

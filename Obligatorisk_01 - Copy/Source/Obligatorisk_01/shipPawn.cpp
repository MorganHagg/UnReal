// Fill out your copyright notice in the Description page of Project Settings.

#include "Obligatorisk_01.h"
#include "shipPawn.h"
#include "Bullet.h"
#include "Alien.h"


// Sets default values to the Player
AshipPawn::AshipPawn()
{
	// Set the Tick funciton to be called every frame
	PrimaryActorTick.bCanEverTick = true;

	// Set the pawn to be controlled by player 1
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Defines the hitbox of bullets
	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));

	// Defines the visible component of the hitbox
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OutVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);



}

// Called when the game starts
void AshipPawn::BeginPlay()
{
	Super::BeginPlay();

	// Sets the cameraview to CameraOne (Camera above the map)
	GetWorld()->GetFirstPlayerController()->SetViewTarget(CameraOne);

	UWorld* World = GetWorld();

	FVector EnemyLocation;

	// Checks if world exists, if it does -> Spawns Aliens
	if (World)
	{
		for (int i = -450; i <= max_Y; i += positionIncrement)
		{
			for (int j = -150; j <= max_X; j += positionIncrement)
			{
				EnemyLocation = FVector(j, i, 40.0f);

				World->SpawnActor<AAlien>(Alien_BP, EnemyLocation, FRotator::ZeroRotator);
			}
		}
	}

}

// Defines the position of the Player
void AshipPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}

}

// Defines the move and shoot functions to the Player
void AshipPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveY", this, &AshipPawn::Move_YAxis);
	InputComponent->BindAction("Shoot", IE_Pressed, this, &AshipPawn::Shoot);


}

// Defines the speed of the Player
void AshipPawn::Move_YAxis(float AxisValue)
{

	CurrentVelocity.Y = FMath::Clamp(AxisValue, -2.0f, 2.0f)*400.0f;



}


// Defines the shooting function (Spawn of Bullets)
void AshipPawn::Shoot()
{
	UWorld* World = GetWorld();

	if (World)
	{
		FVector Location = GetActorLocation();

		World->SpawnActor<ABullet>(Bullet_BP, Location, FRotator::ZeroRotator);

	}

}

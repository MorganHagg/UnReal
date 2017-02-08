
#include "Obligatorisk_01.h"
#include "Bullet.h"
#include "Alien.h"


// Sets default values to Bullets
ABullet::ABullet()
{
	// Set Bullets to call Tick function every frame
	PrimaryActorTick.bCanEverTick = true;

	// Defines hitbox
	RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));
	
	// Defines visible component of Bullets
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));
	OurVisibleComponent->SetupAttachment(RootComponent);

}

// Called when the game starts
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	//Info to Output Log
	UE_LOG(LogTemp, Warning, TEXT("Spawn Bullet"));

	//Checks if there is overlap
	CollisionBox = this->FindComponentByClass<USphereComponent>();

	// Checks if Bullet has collided with Alien
	if (CollisionBox)
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnOverlap);
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Collider"));
	}

}


// Defines Bullet Movement
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Moves bullet up the X axis
	FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
	SetActorLocation(NewLocation);

	FVector Destruction = GetActorLocation();
	//Destroys bullet if X value is at or passes set value, then prints in Output Log
	if (Destruction.X >= 400.0f)
	{
		Destroy();
		UE_LOG(LogTemp, Warning, TEXT("Destruction"));
	}


}
//Checks to see if there is overlapping between Bullet and Alien
void ABullet::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(AAlien::StaticClass()))
	{
		OtherActor->Destroy();
		Destroy();
	}

}
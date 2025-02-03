#include "RotatingActor.h"

ARotatingActor::ARotatingActor() : APlatformBase::APlatformBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();

<<<<<<< Updated upstream
	RotateSpeed = FMath::RandRange(60.0f, 180.0f);
	MajorAxis = FMath::RandRange(1.0f, 3.0f);
	MinorAxis = FMath::RandRange(1.0f, 3.0f);
=======
>>>>>>> Stashed changes
	SetActorRelativeScale3D(FVector(MajorAxis, MinorAxis, 1.0f));

	ensure(!FMath::IsNearlyZero(RotateSpeed));
}

void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));
}


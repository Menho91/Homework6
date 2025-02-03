#include "MovingActor.h"

AMovingActor::AMovingActor() : APlatformBase::APlatformBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	ensure(!FMath::IsNearlyZero(MoveSpeed));
	ensure(!FMath::IsNearlyZero(MaxRange));
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(MoveSpeed * DeltaTime, 0.0f, 0.0f));

	if (MaxRangeSqare < FVector::DistSquared(StartLocation, GetActorLocation()))
	{
		MoveSpeed *= -1.0f;
	}
}


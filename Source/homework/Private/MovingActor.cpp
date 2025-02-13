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

	const float DeltaMove = MoveSpeed * DeltaTime * MovementDirection;
	float NewX = GetActorLocation().X + DeltaMove;

	const float DistanceFromStart = FMath::Abs(StartLocation.X - NewX);
	if (DistanceFromStart > MaxRange)
	{
		NewX -= (DistanceFromStart - MaxRange) * MovementDirection;
		MovementDirection *= -1.f;
	}

	FVector NewLocation = GetActorLocation();
	NewLocation.X = NewX;
	SetActorLocation(NewLocation);
}


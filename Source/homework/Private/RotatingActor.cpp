#include "RotatingActor.h"

ARotatingActor::ARotatingActor() : APlatformBase::APlatformBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();

	SetActorRelativeScale3D(FVector(MajorAxis, MinorAxis, 1.0f));

	ensure(!FMath::IsNearlyZero(RotateSpeed));
}

void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));
}


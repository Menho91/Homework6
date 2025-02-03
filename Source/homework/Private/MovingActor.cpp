#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	MoveSpeed = FMath::RandRange(50.0f, 300.0f);
	MaxRange = FMath::RandRange(100.0f, 200.0f);
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(MoveSpeed) && !FMath::IsNearlyZero(MaxRange))
	{
		AddActorLocalOffset(FVector(MoveSpeed * DeltaTime, 0.0f, 0.0f));
		if (MaxRange < FVector::Distance(StartLocation, GetActorLocation()))
		{
			MoveSpeed *= -1.0f;
		}
	}
}


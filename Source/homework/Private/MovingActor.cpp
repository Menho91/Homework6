#include "MovingActor.h"

AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	MoveSpeed = 90.0f;
	MaxRange = 200.0f;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("%f"), FVector::Distance(StartLocation, GetActorLocation()))

	if (!FMath::IsNearlyZero(MoveSpeed) && !FMath::IsNearlyZero(MaxRange))
	{
		AddActorLocalOffset(FVector(MoveSpeed * DeltaTime, 0.0f, 0.0f));
		if (MaxRange < FVector::Distance(StartLocation, GetActorLocation()))
		{
			MoveSpeed *= -1.0f;
		}
	}
}


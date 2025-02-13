#include "MyActorSpawner.h"
#include "Components/BoxComponent.h"
#include "MovingActor.h"
#include "RotatingActor.h"
#include "TimerActor.h"

AMyActorSpawner::AMyActorSpawner()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneRoot);
}

void AMyActorSpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(ShouldActorSpawn, this, &AMyActorSpawner::SpawnActor, 2, true);
}

void AMyActorSpawner::SpawnActor()
{
	if (ActorToSpawn.Num() == 0)
	{
		return;
	}

	FVector LocationShift(
		FMath::RandRange(-SpawnRange, SpawnRange),
		FMath::RandRange(-SpawnRange, SpawnRange),
		FMath::RandRange(-SpawnZ, SpawnZ));

	FVector SpawnLocation = GetActorLocation() + LocationShift;

	const int32 ClassIndex = FMath::RandRange(0, ActorToSpawn.Num() - 1);
	TSubclassOf<AActor> ChosenActor = ActorToSpawn[ClassIndex];

	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ChosenActor, SpawnLocation, FRotator::ZeroRotator);
	if (SpawnedActor)
	{
		if (AMovingActor* MovingPlatform = Cast<AMovingActor>(SpawnedActor))
		{
			MovingPlatform->MaxRange = FMath::RandRange(200.0f, 500.0f);
			MovingPlatform->MoveSpeed = FMath::RandRange(100.0f, 300.0f);
		}
		else if (ARotatingActor* RotatingPlatform = Cast<ARotatingActor>(SpawnedActor))
		{
			RotatingPlatform->RotateSpeed = FMath::RandRange(60.0f, 180.0f);
			RotatingPlatform->MajorAxis = FMath::RandRange(1.0f, 3.0f);
			RotatingPlatform->MinorAxis = FMath::RandRange(1.0f, 3.0f);
		}
	}
}


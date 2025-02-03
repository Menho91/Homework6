#include "MyActorSpawner.h"
#include "Components/BoxComponent.h"

AMyActorSpawner::AMyActorSpawner()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneRoot);
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	SpawnVolume->SetupAttachment(SceneRoot);

	switch_num = 0;
	BP_Actor = nullptr;
}

void AMyActorSpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(ShouldActorSpawn, this, &AMyActorSpawner::SpawnActor, 2, true);
}

void AMyActorSpawner::SpawnActor()
{
	switch_num++;
	FVector SpawnLocation = GetActorLocation() + FVector(FMath::RandRange(-1000.0f, 1000.0f), FMath::RandRange(-1000.0f, 1000.0f), FMath::RandRange(-500.0f, 500.0f));
	TSubclassOf<class UObject> blockBP = nullptr;

	switch (switch_num % 3)
	{
	case 1:
		BP_Actor = LoadObject<UBlueprint>(nullptr, TEXT("/Game/BP_MovingActor.BP_MovingActor"));
		blockBP = (UClass*)BP_Actor->GeneratedClass;
		if (BP_Actor && blockBP)
		{
			GetWorld()->SpawnActor<AActor>(blockBP, SpawnLocation, FRotator::ZeroRotator);
		}
		break;
	case 2:
		BP_Actor = LoadObject<UBlueprint>(nullptr, TEXT("/Game/BP_RotatingActor.BP_RotatingActor"));
		blockBP = (UClass*)BP_Actor->GeneratedClass;
		if (BP_Actor && blockBP)
		{
			GetWorld()->SpawnActor<AActor>(blockBP, SpawnLocation, FRotator::ZeroRotator);
		}
		break;
	case 0:
		BP_Actor = LoadObject<UBlueprint>(nullptr, TEXT("/Game/BP_TimerActor.BP_TimerActor"));
		blockBP = (UClass*)BP_Actor->GeneratedClass;
		if (BP_Actor && blockBP)
		{
			GetWorld()->SpawnActor<AActor>(blockBP, SpawnLocation, FRotator::ZeroRotator);
		}
		break;
	default:
		break;
	}
}


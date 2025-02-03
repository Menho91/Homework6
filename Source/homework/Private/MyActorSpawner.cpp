#include "MyActorSpawner.h"
#include "Components/BoxComponent.h"
#include "MovingActor.h"
#include "RotatingActor.h"
#include "TimerActor.h"

AMyActorSpawner::AMyActorSpawner()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneRoot);
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	SpawnVolume->SetupAttachment(SceneRoot);

	switch_num = 0;
}

void AMyActorSpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(ShouldActorSpawn, this, &AMyActorSpawner::SpawnActor, 2, true);
}

void AMyActorSpawner::SpawnActor()
{
	switch_num++;
	FVector SpawnLocation = GetActorLocation() + FVector(FMath::RandRange(-300.0f, 300.0f), FMath::RandRange(-300.0f, 300.0f), FMath::RandRange(-500.0f, 500.0f));
	FRotator SpawnRotation = GetActorRotation();
	AActor* Actor = nullptr;
	
	switch (switch_num % 3)
	{
	case 1:
		Actor = GetWorld()->SpawnActor<AMovingActor>(SpawnLocation, SpawnRotation);
		break;
	case 2:
		Actor = GetWorld()->SpawnActor<ARotatingActor>(SpawnLocation, SpawnRotation);
		break;
	case 0:
		Actor = GetWorld()->SpawnActor<ATimerActor>(SpawnLocation, SpawnRotation);
		break;
	default:
		break;
	}

	if (Actor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Successfully Spawned."))
	}
}


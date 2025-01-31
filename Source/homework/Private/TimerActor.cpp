#include "TimerActor.h"

ATimerActor::ATimerActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	VanishTime = 3.0f;
	bVanishSwitch = true;
}

void ATimerActor::VanishActor()
{
	if (bVanishSwitch)
	{
		StaticMeshComp->SetVisibility(false);
		SetActorLocation(StartLocation - FVector(0.0f, 0.0f, 5000.0f));
		bVanishSwitch = false;
	}
	else
	{
		StaticMeshComp->SetVisibility(true);
		SetActorLocation(StartLocation);
		bVanishSwitch = true;
	}
}

void ATimerActor::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();

	GetWorldTimerManager().SetTimer(IsVanishTimer, this, &ATimerActor::VanishActor, VanishTime, true);
}


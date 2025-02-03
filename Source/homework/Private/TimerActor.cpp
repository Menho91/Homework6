#include "TimerActor.h"

ATimerActor::ATimerActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	VanishTime = FMath::RandRange(1.0f, 5.0f);
	bVanishSwitch = true;
}

void ATimerActor::VanishActor()
{
	if (bVanishSwitch)
	{
		StaticMeshComp->SetVisibility(false);
		StaticMeshComp->SetCollisionProfileName(TEXT("NoCollision"));
		bVanishSwitch = false;
	}
	else
	{
		StaticMeshComp->SetVisibility(true);
		StaticMeshComp->SetCollisionProfileName(TEXT("BlockAllDynamic"));
		bVanishSwitch = true;
	}
}

void ATimerActor::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();

	GetWorldTimerManager().SetTimer(IsVanishTimer, this, &ATimerActor::VanishActor, VanishTime, true);
}


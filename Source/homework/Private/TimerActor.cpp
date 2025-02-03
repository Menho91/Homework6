#include "TimerActor.h"

ATimerActor::ATimerActor() : APlatformBase::APlatformBase()
{

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

	GetWorldTimerManager().SetTimer(IsVanishTimer, this, &ATimerActor::VanishActor, VanishTime, true);
}


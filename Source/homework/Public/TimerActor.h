#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformBase.h"
#include "TimerActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class HOMEWORK_API ATimerActor : public APlatformBase
{
	GENERATED_BODY()
	
public:
	ATimerActor();
	void VanishActor();

protected:
	virtual void BeginPlay() override;
	
public:
	FTimerHandle IsVanishTimer;

protected:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties")
	float VanishTime = FMath::RandRange(1.0f, 5.0f);

	bool bVanishSwitch = true;

};

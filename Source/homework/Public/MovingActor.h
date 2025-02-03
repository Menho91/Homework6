#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformBase.h"
#include "MovingActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class HOMEWORK_API AMovingActor : public APlatformBase
{
	GENERATED_BODY()
	
public:	
	AMovingActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties")
	float MaxRange = FMath::RandRange(100.0f, 200.0f);
	float MaxRangeSqare = MaxRange * MaxRange;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties")
	float MoveSpeed = FMath::RandRange(50.0f, 300.0f);;

	FVector StartLocation;

};

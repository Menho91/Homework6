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

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties")
	float MaxRange = 300.0f;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties")
	float MoveSpeed = 100.0f;
	float MovementDirection = 1.f;
	FVector StartLocation;

};

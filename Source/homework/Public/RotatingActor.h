#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformBase.h"
#include "RotatingActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class HOMEWORK_API ARotatingActor : public APlatformBase
{
	GENERATED_BODY()
	
public:	
	ARotatingActor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
public:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties")
	float RotateSpeed = 90.0f;

	float MajorAxis = 2.0f;
	float MinorAxis = 2.0f;

};

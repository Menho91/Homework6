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
	
protected:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties")
	float RotateSpeed = 1.0f;

	float MajorAxis = FMath::RandRange(1.0f, 3.0f);
	float MinorAxis = FMath::RandRange(1.0f, 3.0f);

};

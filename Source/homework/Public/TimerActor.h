#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class HOMEWORK_API ATimerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATimerActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties")
	float VanishTime;

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void VanishActor();
	UPROPERTY()
	FVector StartLocation;
	FTimerHandle IsVanishTimer;
	bool bVanishSwitch;
};

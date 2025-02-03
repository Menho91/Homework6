#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorSpawner.generated.h"

class UBoxComponent;

UCLASS(Blueprintable, BlueprintType)
class HOMEWORK_API AMyActorSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActorSpawner();

	UFUNCTION()
	void SpawnActor();

protected:
	virtual void BeginPlay() override;
	FTimerHandle ShouldActorSpawn;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UBoxComponent* SpawnVolume;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SpawnActor")
	TObjectPtr<UBlueprint> BP_Actor;

	int switch_num;
};

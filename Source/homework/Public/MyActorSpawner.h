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
	void SpawnActor();

protected:
	virtual void BeginPlay() override;
	
public:
	FTimerHandle ShouldActorSpawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UBoxComponent* SpawnVolume;
	
protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SpawnActor")
	TObjectPtr<UBlueprint> BP_Actor = nullptr;

	int switch_num = 0;

};

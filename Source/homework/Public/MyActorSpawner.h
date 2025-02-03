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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* SpawnVolume;

	int switch_num;
};

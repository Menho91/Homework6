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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnOption")
	TArray<TSubclassOf<AActor>> ActorToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnOption")
	float SpawnRange = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnOption")
	float SpawnZ = 500.0f;
};

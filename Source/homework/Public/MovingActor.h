#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class HOMEWORK_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties")
	float MaxRange;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties")
	float MoveSpeed;
	UPROPERTY()
	FVector StartLocation;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class HOMEWORK_API ARotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Properties")
	float RotateSpeed;

	float MajorAxis;
	float MinorAxis;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};

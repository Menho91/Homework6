#include "RotatingActor.h"

ARotatingActor::ARotatingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneRoot);
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	RotateSpeed = 1.0f;
	MajorAxis = 1.0f;
	MinorAxis = 1.0f;
}

void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();

	RotateSpeed = FMath::RandRange(60.0f, 180.0f);
	MajorAxis = FMath::RandRange(1.0f, 3.0f);
	MinorAxis = FMath::RandRange(1.0f, 3.0f);
	SetActorRelativeScale3D(FVector(MajorAxis, MinorAxis, 1.0f));
}

void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotateSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));
	}
}


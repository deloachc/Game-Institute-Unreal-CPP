// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/MovingPlatform.h"

#include "Component/TriggerableActionComponent.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	EndLocationComponent = CreateDefaultSubobject<USceneComponent>(TEXT("EndLocationComponent"));
	EndLocationComponent->SetupAttachment(GetRootComponent());
	
	EndLocationEditorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EndLocationEditorMesh"));
	EndLocationEditorMesh->SetupAttachment(EndLocationComponent);
	EndLocationEditorMesh->SetHiddenInGame(true);
	EndLocationEditorMesh->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);

	TriggerableActionComponent = CreateDefaultSubobject<UTriggerableActionComponent>(TEXT("TriggerableActionComponent"));
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	EndLocation = EndLocationComponent->GetComponentLocation();

	TriggerableActionComponent->OnTriggerActionDelegate.AddDynamic(this, &AMovingPlatform::StartMovePlatformTimeline);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMovingPlatform::InteractWith()
{
	StartMovePlatformTimeline();
}

float AMovingPlatform::GetScaledPlayRate()
{
	float Distance = FVector::Distance(StartLocation, EndLocation);
	float Time = Distance / Speed;
	float PlayRate = 1.f / Time;
	return PlayRate;
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	EndLocationComponent = CreateDefaultSubobject<USceneComponent>(TEXT("EndLocationComponent"));
	EndLocationComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	EndLocation = EndLocationComponent->GetComponentLocation();

	StartMovePlatformTimeline();
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	/*
	// Get the current location of the actor
	FVector StartLocation = GetActorLocation();
	// Multiply the velocity vector by DeltaTime
	FVector DeltaLocation = Velocity * DeltaTime;
	// Add the delta vector to our actor's location to get a new location
	FVector NewLocation = StartLocation + DeltaLocation;
	// Set Actor Location to that new location
	SetActorLocation(NewLocation);
	*/
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


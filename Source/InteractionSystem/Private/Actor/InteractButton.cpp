﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/InteractButton.h"

#include "Component/InteractionComponent.h"
#include "Component/TriggerComponent.h"


// Sets default values
AInteractButton::AInteractButton()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

	TriggerComponent = CreateDefaultSubobject<UTriggerComponent>(TEXT("TriggerComponent"));

	InteractionComponent = CreateDefaultSubobject<UInteractionComponent>(TEXT("InteractionComponent"));
}

// Called when the game starts or when spawned
void AInteractButton::BeginPlay()
{
	Super::BeginPlay();

	InteractionComponent->OnInteractionDelegate.AddDynamic(this, &AInteractButton::ExecuteTriggers);
}

void AInteractButton::ExecuteTriggers()
{
	FString DebugMessage = FString("Execute Triggers on ") + GetHumanReadableName();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, DebugMessage);
	
	TriggerComponent->ExecuteTriggers();
}

// Called every frame
void AInteractButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractButton::InteractWith()
{
	//FString DebugMessage = FString("InteractWith() triggered on ") + GetHumanReadableName();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, DebugMessage);

	//TriggerComponent->ExecuteTriggers();
}


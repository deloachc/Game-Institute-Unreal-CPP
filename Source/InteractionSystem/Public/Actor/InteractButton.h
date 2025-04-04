﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/InteractionInterface.h"
#include "InteractButton.generated.h"

class UInteractionComponent;
class UTriggerComponent;

UCLASS()
class INTERACTIONSYSTEM_API AInteractButton : public AActor, public IInteractionInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInteractButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void ExecuteTriggers();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	/* IInteractionInterface start */
	
	virtual void InteractWith() override;
	
	/* IInteractionInterface end */

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTriggerComponent* TriggerComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInteractionComponent* InteractionComponent;
};

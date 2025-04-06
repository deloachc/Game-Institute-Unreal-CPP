// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InteractionGameMode.generated.h"

/**
 * 
 */
UCLASS()
class INTERACTIONSYSTEM_API AInteractionGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	void AddCollectable(AActor* Collectable);

	void RemoveCollectable(AActor* Collectable);

	int32 GetNumberCollectablesRemaining() const;
	
	
protected:

	UPROPERTY()
	TArray<AActor*> Collectables;
};

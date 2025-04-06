// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InteractionGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCollectablesUpdatedSignature, int32, NumCollectablesRemaining);

UCLASS()
class INTERACTIONSYSTEM_API AInteractionGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	void AddCollectable(AActor* Collectable);

	void RemoveCollectable(AActor* Collectable);

	UFUNCTION(BlueprintPure)
	int32 GetNumberCollectablesRemaining() const;

	void UpdateCollectablesRemaining() const;

	UPROPERTY(BlueprintAssignable)
	FOnCollectablesUpdatedSignature OnCollectablesUpdatedDelegate;
	
	
protected:

	UPROPERTY()
	TArray<AActor*> Collectables;
};

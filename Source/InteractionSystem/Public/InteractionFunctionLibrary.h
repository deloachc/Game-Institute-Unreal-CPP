// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InteractionFunctionLibrary.generated.h"

class AInteractionGameMode;
/**
 * 
 */
UCLASS()
class INTERACTIONSYSTEM_API UInteractionFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintPure)
	static AInteractionGameMode* GetInteractionGameMode(UObject* WorldContextObject);
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionFunctionLibrary.h"

#include "Game/InteractionGameMode.h"
#include "Kismet/GameplayStatics.h"

AInteractionGameMode* UInteractionFunctionLibrary::GetInteractionGameMode(UObject* WorldContextObject)
{
	AInteractionGameMode* GameMode = CastChecked<AInteractionGameMode>(UGameplayStatics::GetGameMode(WorldContextObject));
	if (GameMode)
	{
		return GameMode;
	}

	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString("Game Mode not set to InteractionGameMode"));

	return nullptr;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/InteractionGameMode.h"

void AInteractionGameMode::AddCollectable(AActor* Collectable)
{
	Collectables.AddUnique(Collectable);
	UpdateCollectablesRemaining();
}

void AInteractionGameMode::RemoveCollectable(AActor* Collectable)
{
	Collectables.Remove(Collectable);
	UpdateCollectablesRemaining();

	FString DebugString = FString::FromInt(GetNumberCollectablesRemaining()) + FString(" Collectables Remaining");
	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Emerald, DebugString);
}

int32 AInteractionGameMode::GetNumberCollectablesRemaining() const
{
	return Collectables.Num();
}

void AInteractionGameMode::UpdateCollectablesRemaining() const
{
	OnCollectablesUpdatedDelegate.Broadcast(GetNumberCollectablesRemaining());
}

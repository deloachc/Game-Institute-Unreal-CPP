// Fill out your copyright notice in the Description page of Project Settings.


#include "Interface/InteractionInterface.h"


// Add default functionality here for any IInteractionInterface functions that are not pure virtual.
void IInteractionInterface::InteractWith()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString("Class does not override InteractWith()"));
}

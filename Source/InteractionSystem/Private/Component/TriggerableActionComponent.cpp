// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/TriggerableActionComponent.h"


// Sets default values for this component's properties
UTriggerableActionComponent::UTriggerableActionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTriggerableActionComponent::TriggerAction()
{
	if (!OnTriggerActionDelegate.IsBound())
	{
		FString DebugString = FString("OnTriggerAction not bound on Owner: ") + GetOwner()->GetHumanReadableName();
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow, DebugString);
	}
	
	OnTriggerActionDelegate.ExecuteIfBound();
}

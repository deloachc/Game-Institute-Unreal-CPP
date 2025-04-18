﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "InteractionPromptWidgetComponent.generated.h"


class UInteractionPromptWidget;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INTERACTIONSYSTEM_API UInteractionPromptWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInteractionPromptWidgetComponent();

	void UpdatePromptText(const FString& PromptText);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	UInteractionPromptWidget* PromptWidget;
	
};

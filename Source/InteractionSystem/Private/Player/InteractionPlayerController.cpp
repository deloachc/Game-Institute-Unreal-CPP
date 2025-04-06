// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/InteractionPlayerController.h"

#include "Blueprint/UserWidget.h"

void AInteractionPlayerController::ShowCanvas()
{
	if (!CanvasWidget)
	{
		CanvasWidget = CreateWidget(this, CanvasWidgetClass);
	}
	
	CanvasWidget->AddToViewport();
}

void AInteractionPlayerController::HideCanvas()
{
	if (CanvasWidget)
	{
		CanvasWidget->RemoveFromParent();
	}
}

void AInteractionPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ShowCanvas();
}

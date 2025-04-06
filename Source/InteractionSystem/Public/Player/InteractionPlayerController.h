// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InteractionPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class INTERACTIONSYSTEM_API AInteractionPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	void ShowCanvas();

	void HideCanvas();
	
protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UUserWidget* CanvasWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> CanvasWidgetClass;
};

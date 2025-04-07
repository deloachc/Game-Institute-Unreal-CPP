// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractorComponent.generated.h"

class UInteractionPromptWidget;
class UInteractionComponent;

UENUM(BlueprintType)
enum class EInteractionTraceType : uint8
{
	EITT_CapsuleTrace UMETA(DisplayName = "Capsule Trace"),
	EITT_LineTrace UMETA(DisplayName = "Line Trace")
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INTERACTIONSYSTEM_API UInteractorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInteractorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void DrawDebugSphereForInteractable();

	void CapsuleTrace();

	void LineTraceFromCamera();

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void ExecuteInteractions();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	EInteractionTraceType InteractionTraceType = EInteractionTraceType::EITT_CapsuleTrace;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float TraceStartOffset = 40.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float TraceEndOffset = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float TraceRadius = 40.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float TraceHalfHeight = 90.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	bool bDrawDebugShapes = false;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UInteractionComponent* ClosestInteractable;
	
};

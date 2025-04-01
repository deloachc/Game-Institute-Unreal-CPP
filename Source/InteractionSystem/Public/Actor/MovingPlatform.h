// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/InteractionInterface.h"
#include "MovingPlatform.generated.h"

class UTriggerableActionComponent;

UCLASS()
class INTERACTIONSYSTEM_API AMovingPlatform : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* IInteractionInterface start */
	
	virtual void InteractWith() override;
	
	/* IInteractionInterface end */
	
	UFUNCTION(BlueprintImplementableEvent)
	void StartMovePlatformTimeline();

protected:
	
	UFUNCTION(BlueprintCallable)
	float GetScaledPlayRate();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* EndLocationComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* EndLocationEditorMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTriggerableActionComponent* TriggerableActionComponent;
	
	// cm/second
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 100.f;
	
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	FVector StartLocation = FVector::ZeroVector;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	FVector EndLocation = FVector::ZeroVector;
	
};

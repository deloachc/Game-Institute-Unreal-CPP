// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class INTERACTIONSYSTEM_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MovePlatform(float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartMovePlatformTimeline();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* EndLocationComponent;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	FVector StartLocation = FVector::ZeroVector;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	FVector EndLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Velocity = FVector(200.f, 0.f, 0.f);
};

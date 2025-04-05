﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/InteractorComponent.h"

#include "Component/InteractionComponent.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values for this component's properties
UInteractorComponent::UInteractorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UInteractorComponent::DrawDebugSphereForInteractable()
{
	if (ClosestInteractable && bDrawDebugShapes)
	{
		DrawDebugSphere(GetWorld(), ClosestInteractable->GetOwner()->GetActorLocation(), 30.f, 12, FColor::Green);
	}
}

void UInteractorComponent::CapsuleTrace()
{
	const FVector Start = GetOwner()->GetActorLocation() + GetOwner()->GetActorForwardVector() * TraceStartOffset;
	const FVector End = Start + GetOwner()->GetActorForwardVector() * TraceEndOffset;
	const ETraceTypeQuery TraceChannel = UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_Visibility);
	const TArray<AActor*> ActorsToIgnore = TArray<AActor*>();
	// Ternary Operator: bCondition ? IfTrue : IfFalse
	const EDrawDebugTrace::Type DrawDebugType = bDrawDebugShapes ? EDrawDebugTrace::Type::ForOneFrame : EDrawDebugTrace::Type::None;
	TArray<FHitResult> TraceHits;

	UKismetSystemLibrary::CapsuleTraceMulti(
		this,
		Start,
		End,
		TraceRadius,
		TraceHalfHeight,
		TraceChannel,
		false,
		ActorsToIgnore,
		DrawDebugType,
		TraceHits,
		true
	);

	UInteractionComponent* ReturnClosestInteractable = nullptr;
	
	for (FHitResult& Hit : TraceHits)
	{
		if (Hit.bBlockingHit)
		{
			FString ActorHitName = Hit.GetActor()->GetHumanReadableName();
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, ActorHitName);

			UInteractionComponent* InteractionComponent = Hit.GetActor()->FindComponentByClass<UInteractionComponent>();
			if (InteractionComponent)
			{
				if (ReturnClosestInteractable == nullptr)
				{
					ReturnClosestInteractable = InteractionComponent;
				}
				else
				{
					float DistanceFromPlayer = FVector::Distance(GetOwner()->GetActorLocation(), Hit.GetActor()->GetActorLocation());
					float CurrentClosestDistance = FVector::Distance(GetOwner()->GetActorLocation(), ReturnClosestInteractable->GetOwner()->GetActorLocation());

					if (DistanceFromPlayer < CurrentClosestDistance)
					{
						ReturnClosestInteractable = InteractionComponent;
					}
				}
			}
		}
	}

	ClosestInteractable = ReturnClosestInteractable;
}

void UInteractorComponent::LineTraceFromCamera()
{
	APawn* OwningPawn = Cast<APawn>(GetOwner());
	APlayerController* PlayerController = Cast<APlayerController>(OwningPawn->Controller);
	FVector2D ViewportSize = FVector2D::ZeroVector;
	GEngine->GameViewport->GetViewportSize(ViewportSize);
	FVector WorldLocation = FVector::ZeroVector;
	FVector WorldDirection = FVector::ZeroVector;
	PlayerController->DeprojectScreenPositionToWorld(ViewportSize.X/2.f, ViewportSize.Y/2.f, WorldLocation, WorldDirection);
	
	const FVector Start = WorldLocation + WorldDirection * TraceStartOffset;
	const FVector End = Start + WorldDirection * TraceEndOffset;
	const ETraceTypeQuery TraceChannel = UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_Visibility);
	const TArray<AActor*> ActorsToIgnore = TArray<AActor*>();
	// Ternary Operator: bCondition ? IfTrue : IfFalse
	const EDrawDebugTrace::Type DrawDebugType = bDrawDebugShapes ? EDrawDebugTrace::Type::ForOneFrame : EDrawDebugTrace::Type::None;
	FHitResult TraceHit;

	UKismetSystemLibrary::LineTraceSingle(
		this,
		Start,
		End,
		TraceChannel,
		false,
		ActorsToIgnore,
		DrawDebugType,
		TraceHit,
		true
	);

	if (TraceHit.bBlockingHit)
	{
		UInteractionComponent* InteractionComponent = TraceHit.GetActor()->FindComponentByClass<UInteractionComponent>();
		if (InteractionComponent)
		{
			ClosestInteractable = InteractionComponent;
		}
		else
		{
			ClosestInteractable = nullptr;
		}
	}
	else
	{
		ClosestInteractable = nullptr;
	}
}

// Called every frame
void UInteractorComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	switch (InteractionTraceType)
	{
	case EInteractionTraceType::EITT_CapsuleTrace:
		CapsuleTrace();
		break;
	case EInteractionTraceType::EITT_LineTrace:
		LineTraceFromCamera();
		break;
	default:
		CapsuleTrace();
	}

	DrawDebugSphereForInteractable();
}

void UInteractorComponent::ExecuteInteractions()
{
	if (ClosestInteractable)
	{
		ClosestInteractable->DoInteraction();
	}
}


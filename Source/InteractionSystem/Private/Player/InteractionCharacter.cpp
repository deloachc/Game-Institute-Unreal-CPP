// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/InteractionCharacter.h"

// Sets default values
AInteractionCharacter::AInteractionCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteractionCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractionCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AInteractionCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


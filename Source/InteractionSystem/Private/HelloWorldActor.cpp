// Fill out your copyright notice in the Description page of Project Settings.


#include "HelloWorldActor.h"

// Sets default values
AHelloWorldActor::AHelloWorldActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHelloWorldActor::BeginPlay()
{
	Super::BeginPlay();
	
	SetClassInteger(1);

	SetClassInteger(AddTwoIntegers(3, 3) * 4);

	PrintHelloWorldToLog();
}

// Called every frame
void AHelloWorldActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHelloWorldActor::PrintHelloWorldToLog()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello World"));
}

int32 AHelloWorldActor::AddTwoIntegers(int32 A, int32 B)
{
	return A + B;
}

int32 AHelloWorldActor::GetClassInteger()
{
	return ClassInteger;
}

void AHelloWorldActor::SetClassInteger(int32 NewValue)
{
	ClassInteger = NewValue;
}

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
	
	if (bClassBool)
	{
		UE_LOG(LogTemp, Warning, TEXT("ClassBool is true"));
	}

	if (!bClassBool)
	{
		UE_LOG(LogTemp, Warning, TEXT("ClassBool is false"));
	}

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

void AHelloWorldActor::CompareClassIntegerToInput(int32 Input)
{
	if (ClassInteger == Input)
	{
		UE_LOG(LogTemp, Warning, TEXT("ClassInteger is equal to Input"));
	}
	if (ClassInteger != Input)
	{
		UE_LOG(LogTemp, Warning, TEXT("ClassInteger is not equal to Input"));
	}
}

int32 AHelloWorldActor::GetClassInteger()
{
	return ClassInteger;
}

void AHelloWorldActor::SetClassInteger(int32 NewValue)
{
	ClassInteger = NewValue;
}

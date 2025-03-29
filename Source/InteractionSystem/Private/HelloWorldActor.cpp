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
	
	CompareTwoFloats(ClassFloatA, ClassFloatB);

	ClassVector.X = 2.f;
	ClassVector.Y = 3.f;
	ClassVector.Z = 10.f;

	float VectorLength = ClassVector.Length();
	FVector Normal = ClassVector.GetSafeNormal();

	FVector A = FVector(1.f, 1.f, 1.f);
	FVector B = FVector(3.f);
	
	float Distance = FVector::Distance(A, B);

	ClassRotator.Pitch = 45.f;

	FString DebugString = FString("Debug String");

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, DebugString);

	TArray<FColor> Colors;
	Colors.Emplace(FColor::Red);
	FColor Red = Colors[0];
	Colors.Emplace(FColor::Green);
	FColor Green = Colors[1];
	Colors.Emplace(FColor::Blue);
	
	for (int32 i = 0; i < Colors.Num(); i++)
	{
		FColor Color = Colors[i];
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, Color, FString::FromInt(i));
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

void AHelloWorldActor::CompareTwoFloats(float A, float B)
{
	if (A > B)
	{
		FString DebugString = FString::SanitizeFloat(A) + FString(" is greater than ") + FString::SanitizeFloat(B);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, DebugString);
		UE_LOG(LogTemp, Warning, TEXT("%f is greater than %f"), A, B);
	}
	else if (A < B)
	{
		FString DebugString = FString::SanitizeFloat(A) + FString(" is less than ") + FString::SanitizeFloat(B);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, DebugString);
		UE_LOG(LogTemp, Warning, TEXT("%f is less than %f"), A, B);
	}
	else
	{
		FString DebugString = FString::SanitizeFloat(A) + FString(" is equal to ") + FString::SanitizeFloat(B);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, DebugString);
		UE_LOG(LogTemp, Warning, TEXT("%f is equal to %f"), A, B);
	}
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

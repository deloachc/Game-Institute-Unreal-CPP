// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#include "HelloWorldActor.generated.h"

UCLASS()
class INTERACTIONSYSTEM_API AHelloWorldActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHelloWorldActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PrintHelloWorldToLog();

	int32 AddTwoIntegers(int32 A, int32 B);

	void CompareTwoFloats(float A, float B);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ClassInteger = 2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bClassBool = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ClassFloatA = 2.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ClassFloatB = 5.f;

	void CompareClassIntegerToInput(int32 Input);

	int32 GetClassInteger();

	void SetClassInteger(int32 NewValue);

};

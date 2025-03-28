// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/InteractionCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AInteractionCharacter::AInteractionCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 250.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
}

// Called when the game starts or when spawned
void AInteractionCharacter::BeginPlay()
{
	Super::BeginPlay();

	const APlayerController* PlayerController = Cast<APlayerController>(Controller);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = PlayerController->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	Subsystem->AddMappingContext(DefaultMappingContext, 0);
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

	UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInput->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AInteractionCharacter::Interact);
	EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AInteractionCharacter::Look);
	EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AInteractionCharacter::Move);
}

void AInteractionCharacter::Interact()
{
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString("Interact triggered"));

	const FVector Start = GetActorLocation() + FVector(0.f, 0.f, 75.f);
	const FVector End = Start + (GetActorForwardVector() * 150.f);
	ETraceTypeQuery TraceChannel = UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_Visibility);
	const TArray<AActor*> ActorsToIgnore = TArray<AActor*>();
	EDrawDebugTrace::Type DrawDebugType = EDrawDebugTrace::Type::ForDuration;
	FHitResult Hit;
	
	bool bTraceHit = UKismetSystemLibrary::LineTraceSingle(
		this,
		Start,
		End,
		TraceChannel,
		false,
		ActorsToIgnore,
		DrawDebugType,
		Hit,
		true);

	if (bTraceHit)
	{
		FString ActorHitName = Hit.GetActor()->GetHumanReadableName();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, ActorHitName);
	}
}

void AInteractionCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookInput = Value.Get<FVector2D>();
	
	AddControllerPitchInput(LookInput.Y);
	AddControllerYawInput(LookInput.X);
}

void AInteractionCharacter::Move(const FInputActionValue& Value)
{
	// Get a Vector2D from the Value input
	const FVector2D MoveInput = Value.Get<FVector2D>();
	
	// Find our controller's rotation and isolate the Yaw (left to right rotation)
	const FRotator ControlRotation = GetControlRotation();
	const FRotator YawRotation = FRotator(0.f, ControlRotation.Yaw, 0.f);
	
	// Get the forward and right vectors from the Yaw rotation
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	// Add movement input in the forward and right directions based on our X and Y input values
	AddMovementInput(ForwardDirection, MoveInput.X);
	AddMovementInput(RightDirection, MoveInput.Y);
}

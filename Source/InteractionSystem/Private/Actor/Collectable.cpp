// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/Collectable.h"

#include "Components/SphereComponent.h"

// Sets default values
ACollectable::ACollectable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	Mesh->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));
	SphereCollider->SetupAttachment(Mesh);
	SphereCollider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SphereCollider->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

}

// Called when the game starts or when spawned
void ACollectable::BeginPlay()
{
	Super::BeginPlay();

	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ACollectable::OnSphereBeginOverlap);
}

void ACollectable::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FString DebugString = GetHumanReadableName() + FString(" Collected");
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, DebugString);

	Destroy();
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "PacManPawn.h"
#include "Fruit.h"
#include "Food.h"

// Sets default values
APacManPawn::APacManPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APacManPawn::BeginPlay()
{
	Super::BeginPlay();
	
	// Bind OnOverlapBegin
	OnActorBeginOverlap.AddDynamic(this, &APacManPawn::OnOverlapBegin);
}

// Called every frame
void APacManPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Frozen)
	{
		AddMovementInput(GetActorForwardVector());
	}
}

// Called to bind functionality to input
void APacManPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APacManPawn::SetDirection(const FVector Direction)
{
	if (Direction == FVector::UpVector)
	{
		SetActorRotation(FRotator(0, 270, 0));
	}
	else if (Direction == FVector::DownVector)
	{
		SetActorRotation(FRotator(0, 90, 0));
	}
	else if (Direction == FVector::RightVector)
	{
		SetActorRotation(FRotator(0, 0, 0));
	}
	else if (Direction == FVector::LeftVector)
	{
		SetActorRotation(FRotator(0, 180, 180));
	}

}

bool APacManPawn::IsFrozen()
{
	return Frozen;
}

void APacManPawn::SetFrozen(bool isFrozen)
{
	Frozen = isFrozen;
}

void APacManPawn::OnOverlapBegin(AActor* PlayerActor, AActor* OtherActor)
{
	if (OtherActor->ActorHasTag("Fruit.Regular"))
	{
		Cast<AFruit>(OtherActor)->Consume();
	}

	if (OtherActor->ActorHasTag("Food.PowerUp"))
	{
		Cast<AFood>(OtherActor)->Consume();
	}
}


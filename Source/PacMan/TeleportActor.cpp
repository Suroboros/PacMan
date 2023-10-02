// Fill out your copyright notice in the Description page of Project Settings.


#include "TeleportActor.h"
#include "Engine/Public/TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Components/SceneComponent.h"

// Sets default values
ATeleportActor::ATeleportActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATeleportActor::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &ATeleportActor::OnOverlapBegin);
}

// Called every frame
void ATeleportActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATeleportActor::TeleportToTarget(AActor* Actor)
{
	USceneComponent* TargetSpawn = Cast<USceneComponent>(Target->GetDefaultSubobjectByName("Spawn"));

	UGameplayStatics::PlaySound2D(this, TeleportSound);

	Actor->SetActorLocation(TargetSpawn->GetComponentLocation());
}

void ATeleportActor::OnOverlapBegin(AActor* TeleportActor, AActor* OtherActor)
{
	if (OtherActor->ActorHasTag("PacMan"))
	{
		GetWorldTimerManager().SetTimerForNextTick([OtherActor, this]() { TeleportToTarget(OtherActor); });
	}
}


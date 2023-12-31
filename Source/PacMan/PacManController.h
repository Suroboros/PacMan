// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PacManController.generated.h"

class APacManPawn;

UCLASS()
class PACMAN_API APacManController : public APlayerController
{
	GENERATED_BODY()

protected:
	void SetupInputComponent() override;
	APacManPawn* GetPacMan() const;

public:
	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();
	
};

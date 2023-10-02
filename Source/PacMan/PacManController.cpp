// Fill out your copyright notice in the Description page of Project Settings.


#include "PacManController.h"
#include "PacManPawn.h"

void APacManController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("MoveUp", IE_Pressed, this, &APacManController::MoveUp);
    InputComponent->BindAction("MoveDown", IE_Pressed, this, &APacManController::MoveDown);
    InputComponent->BindAction("MoveRight", IE_Pressed, this, &APacManController::MoveRight);
    InputComponent->BindAction("MoveLeft", IE_Pressed, this, &APacManController::MoveLeft);
}

APacManPawn* APacManController::GetPacMan() const
{
    return Cast<APacManPawn>(GetPawn());
}

void APacManController::MoveUp()
{
    if (GetPacMan() != nullptr)
    {
        GetPacMan()->SetDirection(FVector::UpVector);
    }
}

void APacManController::MoveDown()
{
    if (GetPacMan() != nullptr)
    {
        GetPacMan()->SetDirection(FVector::DownVector);
    }
}

void APacManController::MoveRight()
{
    if (GetPacMan() != nullptr)
    {
        GetPacMan()->SetDirection(FVector::RightVector);
    }
}

void APacManController::MoveLeft()
{
    if (GetPacMan() != nullptr)
    {
        GetPacMan()->SetDirection(FVector::LeftVector);
    }
}

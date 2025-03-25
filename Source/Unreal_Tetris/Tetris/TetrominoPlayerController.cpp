// Fill out your copyright notice in the Description page of Project Settings.


#include "Tetris/TetrominoPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include <Tetris/Tetromino.h>

ATetrominoPlayerController::ATetrominoPlayerController()
{
}

void ATetrominoPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (nullptr != InputMappingContext)
	{
		TArray<FEnhancedActionKeyMapping> Map = InputMappingContext->GetMappings();

		InputSystem->ClearAllMappings();
		InputSystem->AddMappingContext(InputMappingContext, 0);
	}
}

void ATetrominoPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATetrominoPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

}

void ATetrominoPlayerController::MoveLeft()
{
	if (nullptr != Tetromino)
	{
		FVector Dir(0, -1, 0);
		Tetromino->Move(Dir);
	}
}

void ATetrominoPlayerController::MoveRight()
{
	if (nullptr != Tetromino)
	{
		FVector Dir(0, 1, 0);
		Tetromino->Move(Dir);
	}
}

void ATetrominoPlayerController::Rotate()
{
	if (nullptr != Tetromino)
	{
		Tetromino->Rotate();
	}
}

void ATetrominoPlayerController::MoveDown()
{
	if (nullptr != Tetromino)
	{
		FVector Dir(0, 0, -1);
		Tetromino->Move(Dir);
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Tetris/TetrisGameMode.h"
#include <Tetris/Tetromino.h>

ATetrisGameMode::ATetrisGameMode()
{
	TetrominoManager = CreateDefaultSubobject<UTetrominoManager>(TEXT("TetrominoManager"));
}

void ATetrisGameMode::BeginPlay()
{
	Super::BeginPlay();

	TetrominoManager->SpawnTetromino(Subclass);
}

void ATetrisGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

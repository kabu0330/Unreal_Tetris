// Fill out your copyright notice in the Description page of Project Settings.


#include "Tetris/TetrisGameMode.h"
#include <Tetris/Tetromino.h>
#include <Tetris/TetrominoPlayerController.h>
#include <Kismet/GameplayStatics.h>

ATetrisGameMode::ATetrisGameMode()
{
	//TetrominoManager = CreateDefaultSubobject<UTetrominoManager>(TEXT("TetrominoManager"));
}

void ATetrisGameMode::SpawnTetromino()
{
	if (nullptr != Subclass)
	{
		ANewTetromino* NewTetromino = GetWorld()->SpawnActor<ANewTetromino>(Subclass);
		NewTetromino->SetActorLocation(InitLocation);

		ATetrominoPlayerController* PC = Cast<ATetrominoPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
		if (nullptr != PC)
		{
			PC->CotrolledTetromino(NewTetromino);
			NewTetromino->SetController(PC);
		}
	}
}

void ATetrisGameMode::SwitchController(ANewTetromino* Tetromino)
{
	ATetrominoPlayerController* PC = Cast<ATetrominoPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (nullptr != PC)
	{
		PC->CotrolledTetromino(Tetromino);
		Tetromino->SetController(PC);
	}
}

void ATetrisGameMode::BeginPlay()
{
	SetBoudary();
	InitBlockPos();

	Super::BeginPlay();


	//TetrominoManager->SpawnTetromino(Subclass, InitLocation);
}

void ATetrisGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATetrisGameMode::SetBoudary()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < Height; j++)
		{
			AActor* NewBoundaryCube = GetWorld()->SpawnActor<AActor>(BoundaryCube);
			FVector Pos(0, 100 * Width * 0.5f + 50, j * 100 + 100);
			if (1 == i % 2)
			{
				Pos.Y *= -1;
			}

			NewBoundaryCube->SetActorLocation(Pos);
		}
	}
	
}

void ATetrisGameMode::InitBlockPos()
{
	InitLocation.Y = 15;
	InitLocation.Z = Height * 100;
}

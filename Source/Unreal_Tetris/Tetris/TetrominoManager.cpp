// Fill out your copyright notice in the Description page of Project Settings.


#include "Tetris/TetrominoManager.h"
#include <Tetris/TetrominoPlayerController.h>
#include <Kismet/GameplayStatics.h>

// Sets default values for this component's properties
UTetrominoManager::UTetrominoManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTetrominoManager::SpawnTetromino(TSubclassOf<ATetromino> BPTetromino, FVector Pos)
{
	//if (nullptr != BPTetromino)
	//{
	//	ATetromino* NewTetromino = GetWorld()->SpawnActor<ATetromino>(BPTetromino);
	//	NewTetromino->SetActorLocation(Pos);
	//	//NewTetromino->SetTetromino(2);
	//	Tetrominos.Add(NewTetromino);

	//	ATetrominoPlayerController* PC = Cast<ATetrominoPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	//	if (nullptr != PC)
	//	{
	//		PC->CotrolledTetromino(NewTetromino);
	//	}
	//}
}


// Called when the game starts
void UTetrominoManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTetrominoManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


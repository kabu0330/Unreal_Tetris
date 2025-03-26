// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include <Tetris/TetrominoManager.h>
#include <Tetris/NewTetromino.h>
#include "TetrisGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_TETRIS_API ATetrisGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ATetrisGameMode();

	UFUNCTION(BlueprintCallable)
	void SpawnTetromino();

	UFUNCTION(BlueprintCallable)
	void SwitchController(ANewTetromino* Tetromino);

	UFUNCTION(BlueprintCallable)
	FVector GetInitLocation()
	{
		return InitLocation;
	}

protected:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	void SetBoudary();
	void InitBlockPos();

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tetris", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ANewTetromino> Subclass = nullptr;
	
	//UTetrominoManager* TetrominoManager = nullptr;

	FVector InitLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tetris", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> BoundaryCube = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tetris", meta = (AllowPrivateAccess = "true"))
	int Width = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tetris", meta = (AllowPrivateAccess = "true"))
	int Height = 20;

};

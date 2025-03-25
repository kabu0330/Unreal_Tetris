// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include <Tetris/TetrominoManager.h>
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

protected:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tetris", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ATetromino> Subclass = nullptr;
	
	UTetrominoManager* TetrominoManager = nullptr;
};

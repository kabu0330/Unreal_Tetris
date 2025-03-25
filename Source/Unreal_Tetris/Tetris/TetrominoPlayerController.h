// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "TetrominoPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL_TETRIS_API ATetrominoPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATetrominoPlayerController();

	void CotrolledTetromino(class ATetromino* Block)
	{
		Tetromino = Block;
	}

	UFUNCTION(BlueprintCallable)
	void MoveLeft();

	UFUNCTION(BlueprintCallable)
	void MoveRight();

	UFUNCTION(BlueprintCallable)
	void Rotate();

	UFUNCTION(BlueprintCallable)
	void MoveDown();

protected:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	void SetupInputComponent() override;



private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tetris", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* InputMappingContext = nullptr;

	class ATetromino* Tetromino = nullptr;
	
};

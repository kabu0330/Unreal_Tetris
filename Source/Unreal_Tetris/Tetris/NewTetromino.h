// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include <Tetris/TetrominoPlayerController.h>
#include "NewTetromino.generated.h"

UCLASS()
class UNREAL_TETRIS_API ANewTetromino : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANewTetromino();

	void Move(FVector Direction);
	void Rotate();

	UFUNCTION(BlueprintCallable)
	void RequestSpawnTetromino();

	UFUNCTION(BlueprintCallable)
	void RequestSwitchController();

	void SetController(class ATetrominoPlayerController* PlayerController)
	{
		Controller = PlayerController;
	}

	UFUNCTION(BlueprintImplementableEvent, Category = "Event")
	void InputRotationToBP();

	UFUNCTION(BlueprintImplementableEvent, Category = "Event")
	void InputMoveLeftToBP();

	UFUNCTION(BlueprintImplementableEvent, Category = "Event")
	void InputMoveRightToBP();

	UFUNCTION(BlueprintImplementableEvent, Category = "Event")
	void InputMoveDownToBP();

	UFUNCTION(BlueprintCallable, Category = "Event")
	void CallBPCheckLines();

	UFUNCTION(BlueprintPure, Category = "Event")
	FVector GetInitPos();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool CheckCollision(FVector Pos);

private:	
	class ATetrominoPlayerController* Controller = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tetris", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> CheckLineActor = nullptr;

	bool bCanMove = true;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <Tetris/Tetromino.h>
#include "TetrominoManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_TETRIS_API UTetrominoManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTetrominoManager();

	UFUNCTION(BlueprintCallable)
	void SpawnTetromino(TSubclassOf<ATetromino> BPTetromino, FVector Pos);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:	
	UPROPERTY()
	TArray<TObjectPtr<ATetromino>> Tetrominos;


	
		
};

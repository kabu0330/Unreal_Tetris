// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tetromino.generated.h"

UCLASS()
class UNREAL_TETRIS_API ATetromino : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATetromino();

	void SetTetromino(int32 Index);

	void Move(FVector Direction);
	void Rotate();

	void StartTimer();

	UFUNCTION(BlueprintCallable)
	void DropBlock();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Drop();


private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tetris", meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tetris", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Tetromino = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tetris", meta = (AllowPrivateAccess = "true"))
	TArray<UStaticMesh*> Tetrominos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tetris", meta = (AllowPrivateAccess = "true"))
	FTimerHandle TimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tetris", meta = (AllowPrivateAccess = "true"))
	float DropSpeedTime = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tetris", meta = (AllowPrivateAccess = "true"))
	bool bIsDropping = true; 
};

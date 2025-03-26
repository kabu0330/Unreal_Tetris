// Fill out your copyright notice in the Description page of Project Settings.


#include "Tetris/Tetromino.h"
#include <Tetris/Floor.h>
#include "Components/BoxComponent.h"
#include <Engine/World.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
ATetromino::ATetromino()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	Tetromino = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tetromino"));
	//RootComponent = Tetromino;
	
}

void ATetromino::SetTetromino(int32 Index)
{
	if (false == Tetrominos.IsEmpty())
	{
		Tetromino->SetStaticMesh(Tetrominos[Index]);
		
		// 메시 바닥 기준으로 로컬 중점 조정
		//FVector MinBounds, MaxBounds;
		//Tetromino->GetLocalBounds(MinBounds, MaxBounds);
		//FVector Offset = FVector(0, 0, -MinBounds.Z); 

		//Tetromino->SetRelativeLocation(Offset);
	}
}

// Called when the game starts or when spawned
void ATetromino::BeginPlay()
{
	Super::BeginPlay();

	StartTimer();
}

void ATetromino::StartTimer()
{
	FTimerDelegate TimerDelegate;

	TimerDelegate.BindUFunction(this, FName(TEXT("DropBlock")));

	//GetWorld()->GetTimerManager().SetTimer(
	//	TimerHandle,
	//	this,
	//	&ATetromino::DropBlock, // 호출할 함수
	//	DroppingTimer, // N초 후 호출 시작
	//	true  // 반복 호출 여부
	//);
}

void ATetromino::DropBlock()
{
	if (false == bIsDropping)
	{
		return;
	}

	float Value = 100.0f;
	FVector Pos = GetActorLocation();
	SetActorLocation(Pos + FVector(0.0f, 0, -Value));
}

// Called every frame
void ATetromino::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATetromino::Move(FVector Direction)
{
	if (false == bIsDropping)
	{
		return;
	}

	float Value = 100.0f;
	FVector Pos = GetActorLocation();
	SetActorLocation(Pos + FVector(0.0f, Direction.Y * Value, Direction.Z * Value));

}

void ATetromino::Rotate()
{
	FRotator Rotation(0, 0, 90);
	AddActorLocalRotation(Rotation);
}



// Fill out your copyright notice in the Description page of Project Settings.


#include "Tetris/NewTetromino.h"
#include <tetris/TetrisGameMode.h>
#include "Engine/World.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/PrimitiveComponent.h"
#include "CollisionQueryParams.h"
#include "Engine/OverlapResult.h"
#include <Tetris/CheckLineActor.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
ANewTetromino::ANewTetromino()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ANewTetromino::Move(FVector Direction)
{
	float Value = 100.0f;
	FVector Pos = GetActorLocation();
	FVector SetPos = Pos + FVector(0.0f, Direction.Y * Value, Direction.Z * Value);
	SetActorLocation(SetPos);

	//if (false == bCanMove)
	//{
	//	return;
	//}

	//float Value = 100.0f;
	//FVector Pos = GetActorLocation();
	//FVector SetPos = Pos + FVector(0.0f, Direction.Y * Value, Direction.Z * Value);
	//if (false == CheckCollision(SetPos))
	//{
	//	SetActorLocation(SetPos);
	//}
	//else
	//{
	//	bCanMove = false;
	//}
}

void ANewTetromino::Rotate()
{
	FRotator Rotation(0, 0, 90);
	AddActorLocalRotation(Rotation);

	//if (false == bCanMove)
	//{
	//	return;
	//}

	//FRotator Rotation(0, 0, 90);
	//if (false == CheckCollision(GetActorLocation()))
	//{
	//	AddActorLocalRotation(Rotation);
	//}
	//else
	//{
	//	bCanMove = false;
	//}

}

void ANewTetromino::RequestSpawnTetromino()
{
	AGameModeBase* GameModeBase = GetWorld()->GetAuthGameMode();
	ATetrisGameMode* GameMode = Cast<ATetrisGameMode>(GameModeBase);
	if (nullptr != GameMode)
	{
		GameMode->SpawnTetromino();
	}

}

void ANewTetromino::RequestSwitchController()
{
	AGameModeBase* GameModeBase = GetWorld()->GetAuthGameMode();
	ATetrisGameMode* GameMode = Cast<ATetrisGameMode>(GameModeBase);
	if (nullptr != GameMode)
	{
		GameMode->SwitchController(this);
	}
}

void ANewTetromino::CallBPCheckLines()
{
	if (!CheckLineActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("BP 클래스 참조 없음"));
		return;
	}

	TArray<AActor*> FoundActors;

	//  BP_CheckLinesActor를 상속한 C++ 클래스 (ACheckLinesActor)로 찾기
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), CheckLineActor, FoundActors);

	for (AActor* Actor : FoundActors)
	{
		if (Actor)
		{
			FName FunctionName = "CheckLines";  //  BP에서 정의한 함수 이름

			if (Actor->FindFunction(FunctionName))
			{
				Actor->ProcessEvent(Actor->FindFunction(FunctionName), nullptr);
				UE_LOG(LogTemp, Warning, TEXT("BP 함수 호출 성공!"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("BP 함수 없음"));
			}
		}
	}
}

FVector ANewTetromino::GetInitPos()
{
	AGameModeBase* GameModeBase = GetWorld()->GetAuthGameMode();
	ATetrisGameMode* GameMode = Cast<ATetrisGameMode>(GameModeBase);
	if (nullptr != GameMode)
	{
		return GameMode->GetInitLocation();
	}
	return FVector(0, 0, 1500);
}

// Called when the game starts or when spawned
void ANewTetromino::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANewTetromino::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ANewTetromino::CheckCollision(FVector Pos)
{
	//TArray<FOverlapResult> OverlappingActors;
	//FCollisionShape CollisionShape;
	//const FVector3f ShapeScale(50, 50, 50);
	//CollisionShape.SetBox(ShapeScale); // 박스 크기 설정

	//FCollisionQueryParams QueryParams;
	//QueryParams.AddIgnoredActor(this);

	//bool bHit = GetWorld()->OverlapMultiByChannel(
	//	OverlappingActors,
	//	Pos,
	//	FQuat::Identity,
	//	ECC_PhysicsBody,  // 충돌 채널 설정
	//	CollisionShape
	//);

	//return bHit;  // 충돌이 있으면 true 반환
	return false;
}


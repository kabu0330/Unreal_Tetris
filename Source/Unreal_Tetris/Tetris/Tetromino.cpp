// Fill out your copyright notice in the Description page of Project Settings.


#include "Tetris/Tetromino.h"
#include <Tetris/Floor.h>
#include "Components/BoxComponent.h"

// Sets default values
ATetromino::ATetromino()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	Tetromino = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tetromino"));
	Tetromino->SetupAttachment(SceneComponent);
	
	SetActorEnableCollision(true);

	Tetromino->SetNotifyRigidBodyCollision(true);
	Tetromino->SetGenerateOverlapEvents(true);
	Tetromino->SetCollisionProfileName(TEXT("BlockAll"));

	Tetromino->OnComponentHit.AddDynamic(this, &ATetromino::OnHit);
}

void ATetromino::SetTetromino(int32 Index)
{
	if (false == Tetrominos.IsEmpty())
	{
		Tetromino->SetStaticMesh(Tetrominos[Index]);
		
		// 메시 바닥 기준으로 로컬 중점 조정
		FVector MinBounds, MaxBounds;
		Tetromino->GetLocalBounds(MinBounds, MaxBounds);
		FVector Offset = FVector(0, 0, -MinBounds.Z); 

		Tetromino->SetRelativeLocation(Offset);
	}
}

// Called when the game starts or when spawned
void ATetromino::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATetromino::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATetromino::Move(FVector Direction)
{
	float Value = 100.0f;
	FVector Pos = GetActorLocation();
	bool bHit = SetActorLocation(Pos + FVector(0.0f, Direction.Y * Value, Direction.Z * Value));

	if (true == bHit)
	{
		bIsLanded = true;
	}
}

void ATetromino::Rotate()
{
	FRotator Rotation(0, 0, 90);
	AddActorLocalRotation(Rotation);
}

void ATetromino::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (true == OtherComp->IsA(AFloor::StaticClass()))
	{
		FVector Pos = GetActorLocation();
		SetActorLocation({ Pos.X, Pos.Y, 0.0f });
	}
}


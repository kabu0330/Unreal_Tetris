// Fill out your copyright notice in the Description page of Project Settings.


#include "Tetris/Floor.h"
#include <Components/BoxComponent.h>

// Sets default values
AFloor::AFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;

	BoxComponent->SetBoxExtent(FVector(500, 500, 50));

	SetActorEnableCollision(true);
	BoxComponent->SetCollisionProfileName(TEXT("BlockAll"));
	BoxComponent->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


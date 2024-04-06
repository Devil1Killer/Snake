// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodField.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Interactable.h"
#include "Food.h"

// Sets default values
AFoodField::AFoodField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxSpawner = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxSpawner"));
	BoxSpawner->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Delay = 5;

}

// Called when the game starts or when spawned
void AFoodField::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerHandle SpawnDelay;

	GetWorldTimerManager().SetTimer(SpawnDelay, this, &AFoodField::SpawnActor, Delay, SpawnLoop, 1);

}

// Called every frame
void AFoodField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFoodField::SpawnActor() {

	FRotator Rotation(0, 0, 0);
	FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), BoxSpawner->GetScaledBoxExtent());
	GetWorld()->SpawnActor<AActor>(SpawnerClass, RandomLocation, Rotation);

}


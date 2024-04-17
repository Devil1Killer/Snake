// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodField.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/GameInstance.h"
#include "Food.h"

// Sets default values
AFoodField::AFoodField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxSpawner = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxSpawner"));
	BoxSpawner->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or whe   n spawned
void AFoodField::BeginPlay() {
	Super::BeginPlay();

	SpawnActor();

}

// Called every frame
void AFoodField::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void AFoodField::SpawnActor() {

	FRotator Rotation(0, 0, 0);
	FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), BoxSpawner->GetScaledBoxExtent());
	FoundActors.Add(GetWorld()->SpawnActor<AActor>(SpawnerClass, RandomLocation, Rotation));

}

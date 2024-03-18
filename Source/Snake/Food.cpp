// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "SnakeBase.h"
#include "Math/UnrealMathUtility.h"
#include "Bonus.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Xmin = -700.f;
	Xmax = 700.f;
	Ymin = -1300.f;
	Ymax = 1300.f;

}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{

	Super::BeginPlay();

}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFood::Interact(AActor* Interactor, bool bIsHead) {

	int Chance = FMath::RandRange(0, 10);

	if (bIsHead) {

		ASnakeBase* Snake = Cast<ASnakeBase>(Interactor);

		if (IsValid(Snake)) {

			Snake->AddSnakeElement();

			if (Chance == 1) {

				Bonus->SpeedUp(Snake);

			}
			else if (Chance == 2) {

				Bonus->FastGrowth(Snake);

			}
			else {}

			SpawnFood();

			this->Destroy();

		}

	}

}

void AFood::SpawnFood() {


	FVector Location(FMath::RandRange(Xmin, Xmax), FMath::RandRange(Ymin, Ymax), 0);
	FTransform NewTransform(Location);
	GetWorld()->SpawnActor<AFood>(FoodClass, NewTransform);

}

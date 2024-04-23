// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodBonus.h"
#include "SnakeBase.h"
#include "Bonus.h"

// Sets default values
AFoodBonus::AFoodBonus()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFoodBonus::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFoodBonus::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFoodBonus::Interact(AActor* Interactor, bool bIsHead) {

	int Chance = FMath::RandRange(0, 2);

	if (bIsHead) {

		ASnakeBase* Snake = Cast<ASnakeBase>(Interactor);

		if (Chance == 1) {
			
			Bonus->FastGrowth(Snake);

		}
		else if (Chance == 2) {
			
			Bonus->SpeedUp(Snake);

		}

		this->Destroy();


	}

}


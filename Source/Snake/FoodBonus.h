// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "FoodBonus.generated.h"

class ABonus;

UCLASS()
class SNAKE_API AFoodBonus : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoodBonus();

	UPROPERTY()
	ABonus* Bonus;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact(AActor* Interactor, bool bIsHead) override;


};

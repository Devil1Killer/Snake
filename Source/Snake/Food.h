// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Food.generated.h"

class ABonus;

UCLASS()
class SNAKE_API AFood : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFood();

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AFood> FoodClass;

	UPROPERTY()
	ABonus* Bonus;

	UPROPERTY(EditDefaultsOnly)
	float Xmin;

	UPROPERTY(EditDefaultsOnly)
	float Xmax;

	UPROPERTY(EditDefaultsOnly)
	float Ymin;

	UPROPERTY(EditDefaultsOnly)
	float Ymax;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact(AActor* Interactor, bool bIsHead) override;

	UFUNCTION(BlueprintCallable)
	void SpawnFood();

};





// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "FoodField.generated.h"

UCLASS()
class SNAKE_API AFoodField : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoodField();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UBoxComponent* BoxSpawner;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> SpawnerClass;

	UPROPERTY(EditDefaultsOnly)
	float SpawnObjectCount;

	UPROPERTY(EditDefaultsOnly)
	bool SpawnLoop;

	UPROPERTY(EditDefaultsOnly)
	float Delay;

	UFUNCTION(BlueprintCallable)
	void SpawnActor();

};

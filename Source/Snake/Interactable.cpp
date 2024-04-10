// Fill out your copyright notice in the Description page of Project Settings.
//GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, FString::Printf(TEXT("2")));
//GetWorldTimerManager().SetTimer(SpawnDelay, this, &AFoodField::SpawnActor, Delay, SpawnLoop, 1);


//UFUNCTION()
//void OnOverlapBegin(
//	UPrimitiveComponent* OverlappedComponent,
//	AActor* OtherActor,
//	UPrimitiveComponent* OtherComp,
//	int32 OtherBodyIndex,
//	bool bFromSweep,
//	const FHitResult& SweepResult
//);



#include "Interactable.h"

// Add default functionality here for any IInteractable functions that are not pure virtual.


void IInteractable::Interact(AActor* Interactor, bool bIsHead) {



}

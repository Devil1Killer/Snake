// Fill out your copyright notice in the Description page of Project Settings.


#include "Class_HUD.h"
#include "Blueprint/UserWidget.h"

void AClass_HUD::BeginPlay() {

	Super::BeginPlay();

	check(HUDWidget);
	UUserWidget* UserWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), HUDWidget);

	if (UserWidget) {

		UserWidget->AddToViewport();

	}

}

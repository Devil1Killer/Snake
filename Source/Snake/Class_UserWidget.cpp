// Fill out your copyright notice in the Description page of Project Settings.


#include "Class_UserWidget.h"
#include "PlayerPawnBase.h"

void UClass_UserWidget::NativeConstruct() {

	Super::NativeConstruct();
	APlayerPawnBase* CourseCharacter = Cast<APlayerPawnBase>(GetOwningPlayerPawn());

	if (CourseCharacter) {

		CourseCharacter->Score.AddDynamic(this, &ThisClass::ScoreIncrease);

	}
}

void UClass_UserWidget::ScoreIncrease(const float NewScore) {

	check(ScoreWidget);
	ScoreWidget->SetText(FText::AsNumber(NewScore));

}

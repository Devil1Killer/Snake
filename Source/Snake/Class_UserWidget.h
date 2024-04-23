// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>
#include "Class_UserWidget.generated.h"

UCLASS(Abstract)
class SNAKE_API UClass_UserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeConstruct() override;

protected:

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreWidget;

private:

	UFUNCTION()
	void ScoreIncrease(const float NewScore);


};

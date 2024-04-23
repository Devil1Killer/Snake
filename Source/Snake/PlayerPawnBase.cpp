// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnBase.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "SnakeBase.h"
#include "Components/InputComponent.h"

// Sets default values
APlayerPawnBase::APlayerPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
	RootComponent = PawnCamera;

}

// Called when the game starts or when spawned
void APlayerPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorRotation(FRotator(-90,0,0));

	CreateSnakeActor();

}

// Called every frame
void APlayerPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Vertical", this, &APlayerPawnBase::HandlePlayerVerticalInput);
	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerPawnBase::HandlePlayerHorizontalInput);

	PlayerInputComponent->BindAction("Acceleration", IE_Pressed, this, &APlayerPawnBase::Acceleration);
	PlayerInputComponent->BindAction("Acceleration", IE_Released, this, &APlayerPawnBase::OffAcceleration);

}

void APlayerPawnBase::CreateSnakeActor() {

	SnakeActor = GetWorld()->SpawnActor<ASnakeBase>(SnakeActorClass, FTransform());


}

void APlayerPawnBase::HandlePlayerVerticalInput(float value) {

	if (IsValid(SnakeActor)) {

		if (value > 0 && SnakeActor->LastMoveDirection!= EMovementDirection::DOWN && SnakeActor->DelayBeforeMove == true) {

			SnakeActor->LastMoveDirection = EMovementDirection::UP;
			SnakeActor->DelayBeforeMove = false;
			
		}
		else if (value < 0 && SnakeActor->LastMoveDirection != EMovementDirection::UP && SnakeActor->DelayBeforeMove == true){

			SnakeActor->LastMoveDirection = EMovementDirection::DOWN;
			SnakeActor->DelayBeforeMove = false;

		}

	}

}

void APlayerPawnBase::HandlePlayerHorizontalInput(float value) {

	if (IsValid(SnakeActor)) {

		if (value > 0 && SnakeActor->LastMoveDirection != EMovementDirection::LEEFT && SnakeActor->DelayBeforeMove == true) {

			SnakeActor->LastMoveDirection = EMovementDirection::RIGHT;
			SnakeActor->DelayBeforeMove = false;

		}
		else if (value < 0 && SnakeActor->LastMoveDirection != EMovementDirection::RIGHT && SnakeActor->DelayBeforeMove == true) {

			SnakeActor->LastMoveDirection = EMovementDirection::LEEFT;
			SnakeActor->DelayBeforeMove = false;

		}

	}

}

void APlayerPawnBase::Acceleration() {

	if (IsValid(SnakeActor)) {

		SnakeActor->SetActorTickInterval(SnakeActor->MovementSpeed / 2);

	}

}

void APlayerPawnBase::OffAcceleration() {

	if (IsValid(SnakeActor)) {

		SnakeActor->SetActorTickInterval(SnakeActor->MovementSpeed * 2);

	}

}


void APlayerPawnBase::Scoring() {

	ScorePlayer += 100;

	Score.Broadcast(ScorePlayer);

}


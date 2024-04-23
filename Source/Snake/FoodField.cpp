// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodField.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/GameInstance.h"
#include "Food.h"

// Sets default values
AFoodField::AFoodField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxSpawner = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxSpawner"));
	BoxSpawner->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or whe   n spawned
void AFoodField::BeginPlay() {
	Super::BeginPlay();

	SpawnActor();

}

// Called every frame
void AFoodField::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void AFoodField::SpawnActor() {

	bool bCanMove = true;

	FRotator Rotation(0, 0, 0);
	//FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), BoxSpawner->GetScaledBoxExtent());
	FoundActors.Add(GetWorld()->SpawnActor<AActor>(SpawnerClass, CheckingCollisionsWithObjects(16, FoundActors, true, 100), Rotation));
	//CheckingCollisionsWithObjects(16, FoundActors, true, 10, bCanMove)
}

void AFoodField::SpawnBonusActor() {

	bool bCanMove = true;

	FRotator Rotation(0, 0, 0);
	FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), BoxSpawner->GetScaledBoxExtent());
	GetWorld()->SpawnActor<AActor>(SpawnerBonusClass, RandomLocation, Rotation);

}


FVector AFoodField::CheckingCollisionsWithObjects(
	float Radius,
	const TArray<AActor*> ActorsToIgnore,
	bool DrawDebugeContext, const int TryCount) const 
{

	const UWorld* World = GetWorld();
	const UGameInstance* GameInstance = Cast<UGameInstance>(GetGameInstance());

	if (World == nullptr || GameInstance == nullptr) return FVector::ZeroVector;

	EDrawDebugTrace::Type DebugTrace = EDrawDebugTrace::None;
	if (DrawDebugeContext) DebugTrace = EDrawDebugTrace::ForDuration;

	for (int Attempt = 0; Attempt < TryCount; ++Attempt) {

		FVector SpawnPoint = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), BoxSpawner->GetScaledBoxExtent());

		// ѕровер€ем коллизии вокруг точки спавна
		FHitResult HitResult;

		bool bHit = UKismetSystemLibrary::SphereTraceSingle(
			World,
			SpawnPoint,
			SpawnPoint,
			Radius,
			UEngineTypes::ConvertToTraceType(ECC_Visibility),
			true,
			ActorsToIgnore,
			DebugTrace,
			HitResult,
			true,
			FLinearColor::Green,
			FLinearColor::Red,
			5.0f);

		if (!bHit && !HitResult.bBlockingHit) {

			return SpawnPoint; // “очка свободна, возвращаем ее

		}

	}

	return FVector::ZeroVector; // ≈сли не удалось найти свободную точку после MaxAttempts попыток

}


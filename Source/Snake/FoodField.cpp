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

// Called when the game starts or when spawned
void AFoodField::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFoodField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), SpawnerClass, FoundActors);

	if (FoundActors.Num() <= 1000) {

		SpawnActor();

	}

}

void AFoodField::SpawnActor() {

	bool bCanMove;
	FRotator Rotation(0, 0, 0);
	//FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), BoxSpawner->GetScaledBoxExtent());

	FoundActors.Add(GetWorld()->SpawnActor<AActor>(SpawnerClass, CheckingCollisionsWithObjects(16, FoundActors, true, 10, bCanMove), Rotation));

}

FVector AFoodField::CheckingCollisionsWithObjects(
	float Radius, 
	const TArray<AActor*> ActorsToIgnore, 
	bool DrawDebugeContext, const int TryCount, 
	bool& bCanMove) const
{

	bCanMove = false;
	const UWorld* World = GetWorld();
	const  UGameInstance* GameIstance = Cast<UGameInstance>(GetGameInstance());
	if (World == nullptr || GameIstance == nullptr) FVector::ZeroVector;

	EDrawDebugTrace::Type DebugTrace = EDrawDebugTrace::None;
	if (DrawDebugeContext) DebugTrace = EDrawDebugTrace::ForDuration;

	int iterator = 0;
	FHitResult HitResult;


	while (iterator < TryCount) {

		FVector CollisionPoint = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), BoxSpawner->GetScaledBoxExtent());
		
		UKismetSystemLibrary::SphereTraceSingle(
			World, 
			CollisionPoint,
			CollisionPoint, 
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

		if (HitResult.bBlockingHit == false) {

			bCanMove = true;
			return CollisionPoint;

		}	

		iterator++;

	}

	return FVector::ZeroVector;

}
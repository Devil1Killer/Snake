// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "SnakeBase.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerPawnBase.h"
#include "FoodField.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(Root);

	Mesh->SetWorldScale3D(FVector(0.3f, 0.3f, 0.3f));

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AFood::OnOverlapBegin);
	Trigger->SetWorldScale3D(FVector(1.5f, 1.5f, 1.5f));
	Trigger->AttachTo(Mesh);

}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{

	Super::BeginPlay();

}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFood::Interact(AActor* Interactor, bool bIsHead) {

	int Chance = FMath::RandRange(0, 5);
	Chance = 1;
	if (bIsHead) {

		ASnakeBase* Snake = Cast<ASnakeBase>(Interactor);

		if (IsValid(Snake)) {

			UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerPawnBase::StaticClass(), Pawns);

			for (AActor* Paw : Pawns) {

				APlayerPawnBase* Pawn = Cast<APlayerPawnBase>(Paw);

				if (IsValid(Pawn)) {

					Pawn->Scoring();

				}

			}

			Snake->AddSnakeElement();

			UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFoodField::StaticClass(), Foods);

			for (AActor* Food : Foods) {

				AFoodField* FoodField = Cast<AFoodField>(Food);

				if (IsValid(FoodField)) {
					
					FoodField->SpawnActor();

					if (Chance == 1) {
					
						FoodField->SpawnBonusActor();

					}

				}

			}

			this->Destroy();

		}

	}

}

void AFood::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)) {

	}

}

void AFood::CollisionCheck() {

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFoodField::StaticClass(), Foods);

	for (AActor* Food : Foods) {

		AFoodField* FoodField = Cast<AFoodField>(Food);

		if (IsValid(FoodField)) {
			
			FoodField->SpawnActor();

		}

	}

	//this->Destroy();

}



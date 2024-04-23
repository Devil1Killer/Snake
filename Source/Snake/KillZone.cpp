// Fill out your copyright notice in the Description page of Project Settings.


#include "KillZone.h"
#include "Kismet/GameplayStatics.h"
#include "SnakeElementBase.h"
#include "SnakeBase.h"
// Sets default values
AKillZone::AKillZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(Root);

	//Mesh->SetWorldScale3D(FVector(0.3f, 0.3f, 0.3f));

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &AKillZone::OnOverlapBegin);
	//Trigger->SetWorldScale3D(FVector(1.5f, 1.5f, 1.5f));
	Trigger->AttachTo(Mesh);

}

// Called when the game starts or when spawned
void AKillZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKillZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKillZone::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)) {

	}

}

void AKillZone::Interact(AActor* Interactor, bool bIsHead) {

	ASnakeBase* Snake = Cast<ASnakeBase>(Interactor);

	if (IsValid(Snake)) {

		Snake->Destroy();

		for (int i = 0; i < Snake->SnakeElements.Num(); i++) {

			Snake->SnakeElements[i]->Destroy();

		}

	}

}


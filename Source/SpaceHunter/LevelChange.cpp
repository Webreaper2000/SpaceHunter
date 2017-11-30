// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceHunterX.h"
#include "LevelChange.h"
#include "SpaceHunterXGameMode.h"

// Sets default values
ALevelChange::ALevelChange()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	LevelCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("collision"));
	RootComponent = LevelCollision;
	LevelCollision->SetBoxExtent(FVector(7.0f, 5.0f, 6.6f));
	LevelCollision->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	LevelCollision->SetCollisionProfileName("Level");
	
}

// Called when the game starts or when spawned
void ALevelChange::BeginPlay()
{
	Super::BeginPlay();
	UWorld* world = GetWorld();

	if (world)
	{

		ASpaceHunterXGameMode* GameMode = Cast<ASpaceHunterXGameMode>(world->GetAuthGameMode());
		if (GameMode)
		{
			SpawnName = GameMode->NameTest;
		}
	}
}

// Called every frame
void ALevelChange::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ALevelChange::OnActorHit()
{
	UE_LOG(LogTemp, Warning, TEXT("Your message"));
	
}


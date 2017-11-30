// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LevelChange.generated.h"

UCLASS()
class SPACEHUNTERX_API ALevelChange : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelChange();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	virtual void OnActorHit();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Object)
		FName SpawnName = "test1";



	UPROPERTY(EditAnywhere)
		UBoxComponent *LevelCollision;
	
};

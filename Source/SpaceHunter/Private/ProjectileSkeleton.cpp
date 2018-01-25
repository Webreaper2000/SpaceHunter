// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileSkeleton.h"


// Sets default values
AProjectileSkeleton::AProjectileSkeleton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectileSkeleton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileSkeleton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


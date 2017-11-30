// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PaperSpriteComponent.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class SPACEHUNTERX_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;


	UPROPERTY(EditAnywhere)
		UPaperSpriteComponent* Player;

	UPROPERTY(EditAnywhere)
		UFloatingPawnMovement* PlayerControl;

	UPROPERTY(EditAnywhere)
		UBoxComponent *collision;

	

	void	MoveX_Axis(float AxisValue);
	void MoveZ_Axis(float AxisValue);
	
};

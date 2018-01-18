// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PaperSpriteComponent.h"
#include "PaperFlipbookComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class SPACEHUNTER_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere)
		UPaperSpriteComponent* Player;

	UPROPERTY(EditAnywhere)
		UFloatingPawnMovement* PlayerControl;

	UPROPERTY(EditAnywhere)
		UBoxComponent *collision;



	void	MoveX_Axis(float AxisValue);
	void MoveZ_Axis(float AxisValue);

	
};

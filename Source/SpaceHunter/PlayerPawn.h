// Fill out your copyright notice in the Description page of Project Settings.
#pragma once



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

	//added class to these makes it work, paper2D stuff needs to be looked into

	/*UPROPERTY(EditAnywhere)
	class	UPaperSpriteComponent* Player;*/

	UPROPERTY(EditAnywhere)
	class	UFloatingPawnMovement* PlayerControl;

	UPROPERTY(EditAnywhere)
	class	UBoxComponent* collision;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void	MoveX_Axis(float AxisValue);
	void MoveZ_Axis(float AxisValue);
	
};

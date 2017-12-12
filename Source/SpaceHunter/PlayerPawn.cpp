// Fill out your copyright notice in the Description page of Project Settings.
#include "PlayerPawn.h"
#include "SpaceHunter.h"



// Sets default values
APlayerPawn::APlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	APlayerPawn::APlayerPawn(const FObjectInitializer& ObjectInitializer)

	collision = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(TEXT("collision"));
	RootComponent = collision;
	collision->SetBoxExtent(FVector(7.0f, 5.0f, 6.6f));
	collision->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	collision->SetCollisionProfileName("Pawn");


	PlayerControl = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	PlayerControl->SetUpdatedComponent(RootComponent);
	PlayerControl->MaxSpeed = 200.0f;
	PlayerControl->Acceleration = PlayerControl->MaxSpeed * 5;
	PlayerControl->Deceleration = PlayerControl->MaxSpeed * 5;


	UCameraComponent* PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	Player = CreateDefaultSubobject< UPaperSpriteComponent>(TEXT("PlayerSprite"));
	Player->SetSprite(ConstructorHelpers::FObjectFinder<UPaperSprite>(TEXT("PaperSprite'/Game/Sprites/Character_sprites/character_Sprite_0.character_Sprite_0'")).Object);
	Player->SetRelativeLocation(FVector(0.0f, 0.0f, 1.0f));
	Player->SetupAttachment(RootComponent);
	Player->SetCollisionProfileName(TEXT("Collision"));

	USpringArmComponent *springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	springArm->SetupAttachment(RootComponent);
	springArm->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	springArm->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	springArm->SetAbsolute(false, false, false);
	springArm->TargetArmLength = 0.0f;
	springArm->bEnableCameraLag = false;
	springArm->CameraLagSpeed = 0.0f;

	PlayerCamera->SetupAttachment(RootComponent);
	PlayerCamera->SetRelativeLocation(FVector(0.0f, 200.0f, 0.0f));
	PlayerCamera->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
	PlayerCamera->ProjectionMode = ECameraProjectionMode::Orthographic;
	PlayerCamera->SetupAttachment(springArm, USpringArmComponent::SocketName);




}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveX", this, &APlayerPawn::MoveX_Axis);
	InputComponent->BindAxis("MoveZ", this, &APlayerPawn::MoveZ_Axis);


}

void APlayerPawn::MoveX_Axis(float AxisValue)
{
	FVector input = FVector(AxisValue, 0.0f, 0.0f);
	AddMovementInput(input);


}
void APlayerPawn::MoveZ_Axis(float AxisValue)
{
	FVector Input = FVector(0.0f, 0.0f, AxisValue);
	AddMovementInput(Input);

}

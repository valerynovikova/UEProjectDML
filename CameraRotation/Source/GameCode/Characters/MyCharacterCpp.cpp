// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterCpp.h"

// Sets default values
AMyCharacterCpp::AMyCharacterCpp()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp);
	CameraComp->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void AMyCharacterCpp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacterCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacterCpp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("FB", this, &AMyCharacterCpp::MoveForward);
	PlayerInputComponent->BindAxis("LR", this, &AMyCharacterCpp::MoveRight);

	PlayerInputComponent->BindAxis("lookLR", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("lookUD", this, &APawn::AddControllerPitchInput);


}

void AMyCharacterCpp::MoveForward(float value)
{
	if ((Controller != NULL) && (value != 0)) 
	{
		const FRotator Rot = Controller->GetControlRotation();
		const FRotator YawRot(0, Rot.Yaw, 0);

		const FVector Dir = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
		AddMovementInput(Dir, value);
	}

}

void AMyCharacterCpp::MoveRight(float value)
{
	if ((Controller != NULL) && (value != 0)) 
	{
		const FRotator Rot = Controller->GetControlRotation();
		const FRotator YawRot(0, Rot.Yaw, 0);

		const FVector Dir = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);
		AddMovementInput(Dir, value);
	}

}

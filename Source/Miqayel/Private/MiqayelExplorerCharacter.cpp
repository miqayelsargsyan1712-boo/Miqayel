#include "MiqayelExplorerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMiqayelExplorerCharacter::AMiqayelExplorerCharacter()
{
    GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

    bUseControllerRotationYaw = true;
    GetCharacterMovement()->bOrientRotationToMovement = false;
    GetCharacterMovement()->MaxWalkSpeed = 600.0f;

    USpringArmComponent* CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 0.0f;
    CameraBoom->bUsePawnControlRotation = true;

    UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = false;
    Camera->SetRelativeLocation(FVector(0.0f, 0.0f, 64.0f));
}

void AMiqayelExplorerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMiqayelExplorerCharacter::MoveForward);
    PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMiqayelExplorerCharacter::MoveRight);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMiqayelExplorerCharacter::Turn);
    PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMiqayelExplorerCharacter::LookUp);
}

void AMiqayelExplorerCharacter::MoveForward(float Value)
{
    if (Controller && Value != 0.0f)
    {
        AddMovementInput(GetActorForwardVector(), Value);
    }
}

void AMiqayelExplorerCharacter::MoveRight(float Value)
{
    if (Controller && Value != 0.0f)
    {
        AddMovementInput(GetActorRightVector(), Value);
    }
}

void AMiqayelExplorerCharacter::Turn(float Value)
{
    AddControllerYawInput(Value);
}

void AMiqayelExplorerCharacter::LookUp(float Value)
{
    AddControllerPitchInput(Value);
}

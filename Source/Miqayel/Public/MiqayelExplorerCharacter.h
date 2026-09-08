#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MiqayelExplorerCharacter.generated.h"

UCLASS()
class MIQAYEL_API AMiqayelExplorerCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AMiqayelExplorerCharacter();

protected:
    virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
    void MoveForward(float Value);
    void MoveRight(float Value);
    void Turn(float Value);
    void LookUp(float Value);
};

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DSAnimInstance.generated.h"

UCLASS()
class DARKSOUL_API UDSAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	class ACharacter* Character;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	class UCharacterMovementComponent* CharacterMovement;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Data")
	FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Data")
	float GroundSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Data")
	bool bShouldMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement Data")
	bool bIsFalling;

public:
	UDSAnimInstance();

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
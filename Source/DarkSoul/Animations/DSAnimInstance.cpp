#include "Animations/DSAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UDSAnimInstance::UDSAnimInstance()
{
}

void UDSAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Character = Cast<ACharacter>(GetOwningActor());

	if (Character)
	{
		CharacterMovement = Character->GetCharacterMovement();
	}
}

void UDSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (Character == nullptr || CharacterMovement == nullptr)
	{
		return;
	}

	Velocity = CharacterMovement->Velocity;
	GroundSpeed = Velocity.Size2D();

	bShouldMove = GroundSpeed > 3.f && CharacterMovement->GetCurrentAcceleration() != FVector::ZeroVector;

	bIsFalling = CharacterMovement->IsFalling();
}
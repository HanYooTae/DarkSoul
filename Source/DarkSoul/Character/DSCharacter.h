#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DSCharacter.generated.h"

struct FInputActionValue;

UCLASS()
class DARKSOUL_API ADSCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere)
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere)
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere)
	class UInputAction* LookAction;

public:
	ADSCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	//Controller에 빙의되었을 때 호출되는 함수
	virtual void NotifyControllerChanged() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void Move(const FInputActionValue& Values);
	void Look(const FInputActionValue& Values);
};

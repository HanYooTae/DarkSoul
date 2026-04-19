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

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* SprintAction;

private:
	class UDSAttributeComponent* AttributeComponent;

protected:
	// 달리기 속도
	UPROPERTY(EditAnywhere, Category = "Sprinting")
	float SprintingSpeed = 750.f;

	// 일반 이동 속도
	UPROPERTY(EditAnywhere, Category = "Sprinting")
	float NormalSpeed = 500.f;

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
	bool IsMoving() const;

	void Move(const FInputActionValue& Values);
	void Look(const FInputActionValue& Values);

	void Sprinting();
	void StopSprint();
};

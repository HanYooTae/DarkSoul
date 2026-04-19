#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DSAttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DARKSOUL_API UDSAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Stamina")
	float BaseStamina = 100.f;

	UPROPERTY(EditAnywhere, Category = "Stamina")
	float MaxStamina = 100.f;

	UPROPERTY(EditAnywhere, Category = "Stamina")
	float StaminaRegenRate = 0.2f; // 스태미나 재충전량

	// 스태미나 재충전 타이머 핸들
	FTimerHandle StaminaRechargeTimerHandle;

public:
	UDSAttributeComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	FORCEINLINE float GetBaseStamina() const { return BaseStamina; }
	FORCEINLINE float GetMaxStamina() const { return MaxStamina; }

	// 스태미너가 충분한지 체크
	bool CheckHasEnoughStamina(float StaminaCost) const;

	// 스테미나 소비
	void DecreaseStamina(float StaminaCost);

	// 스태미나 재충전/중지 토클
	void ToggleStaminaRecharge(bool bEnabled, float StartDelay = 2.f);

private:
	// 스태미나 재충전 함수
	void RechargeStaminaHandler();
};

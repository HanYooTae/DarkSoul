#include "Components/DSAttributeComponent.h"

UDSAttributeComponent::UDSAttributeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UDSAttributeComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UDSAttributeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

bool UDSAttributeComponent::CheckHasEnoughStamina(float StaminaCost) const
{
	return BaseStamina >= StaminaCost;
}

void UDSAttributeComponent::DecreaseStamina(float StaminaCost)
{
	BaseStamina = FMath::Clamp(BaseStamina - StaminaCost, 0.f, MaxStamina);
}

void UDSAttributeComponent::ToggleStaminaRecharge(bool bEnabled, float StartDelay)
{
	if (bEnabled)
	{
		if (GetWorld()->GetTimerManager().IsTimerActive(StaminaRechargeTimerHandle) == false)
		{
			GetWorld()->GetTimerManager().SetTimer(StaminaRechargeTimerHandle, this, &ThisClass::RechargeStaminaHandler, 0.1f, true, StartDelay);
		}
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(StaminaRechargeTimerHandle);
	}
}

void UDSAttributeComponent::RechargeStaminaHandler()
{
	BaseStamina = FMath::Clamp(BaseStamina + StaminaRegenRate, 0.f, MaxStamina);

	if (BaseStamina >= MaxStamina)
	{
		ToggleStaminaRecharge(false);
	}
}


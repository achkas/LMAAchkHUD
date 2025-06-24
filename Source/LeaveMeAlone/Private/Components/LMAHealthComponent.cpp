//  LeaveMeAlone Game by Netologiya. All Rights Reserved


#include "Components/LMAHealthComponent.h"

ULMAHealthComponent::ULMAHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool ULMAHealthComponent::IsDead() const
{
	return Health <= 0.0f;
}

bool ULMAHealthComponent::AddHealth(float NewHealth)
{
	if (IsDead() || IsHealthFull())
		return false;

	Health = FMath::Clamp(Health + NewHealth, 0.0f, MaxHealth);
	OnHealthChanged.Broadcast(Health);
	return true;
}

bool ULMAHealthComponent::IsHealthFull() const
{
	return FMath::IsNearlyEqual(Health, MaxHealth);
}

void ULMAHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	OnHealthChanged.Broadcast(Health);

	AActor* OwnerComponent = GetOwner();
	if (OwnerComponent)
	{
		OwnerComponent->OnTakeAnyDamage.AddDynamic(this, &ULMAHealthComponent::OnTakeAnyDamage);
	}
}


//Далее, если мы умерли после получения урона, то наш делегат оповестит всех подписавшихся клиентов, 
//что у них недостаточно здоровья.Функция Broadcast отвечает за оповещение всех подписавшихся
//объектов.Но в настоящее время мы ещё не подписались на делегат ни в одном из классов.В связи с чем,
//переходим в заголовочный файл LMADefaultCharacter.h и продолжаем работу.
void ULMAHealthComponent::OnTakeAnyDamage(
	AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (IsDead())
		return;

	Health = FMath::Clamp(Health - Damage, 0.0f, MaxHealth);
	OnHealthChanged.Broadcast(Health);

	if (IsDead())
	{
		OnDeath.Broadcast();//оповестит всех подписавшихся клиентов
	}
}

float ULMAHealthComponent::GetHealth() const
{
	return Health;
}


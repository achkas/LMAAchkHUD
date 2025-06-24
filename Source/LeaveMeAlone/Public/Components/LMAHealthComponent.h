//  LeaveMeAlone Game by Netologiya. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LMAHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath)// Декларируем делегат
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class LEAVEMEALONE_API ULMAHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	ULMAHealthComponent();

	UFUNCTION(BlueprintCallable)
	float GetHealth() const;

	/*UFUNCTION(BlueprintCallable)
	float GetHealth() const;*/



	UFUNCTION(BlueprintCallable)//Далее нам необходимо объявить функцию, которая будет обрабатывать оповещать клиентов о смерти, в случае потери здоровья.
	bool IsDead() const;

	bool AddHealth(float NewHealth);
	bool IsHealthFull() const;

	FOnDeath OnDeath;//Так как условия смерти будут контролироваться в компоненте здоровья, нам необходимо в нем объявить задекларированный делегат

	FOnHealthChanged OnHealthChanged;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float MaxHealth = 100.0f;

	virtual void BeginPlay() override;

private:
	float Health = 0.0f;

	UFUNCTION()
	void OnTakeAnyDamage(
		AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);
};

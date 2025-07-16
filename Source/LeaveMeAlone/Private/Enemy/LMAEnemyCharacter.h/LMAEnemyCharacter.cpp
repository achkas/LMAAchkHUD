//  LeaveMeAlone Game by Netologiya. All Rights Reserved


#include "Enemy/LMAEnemyCharacter.h/LMAEnemyCharacter.h"
#include "Components/LMAHealthComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


ALMAEnemyCharacter::ALMAEnemyCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	HealthComponent = CreateDefaultSubobject<ULMAHealthComponent>("HealthComponent");
	
}


void ALMAEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


void ALMAEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}






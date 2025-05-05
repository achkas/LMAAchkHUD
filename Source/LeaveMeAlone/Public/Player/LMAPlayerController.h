//  LeaveMeAlone Game by Netologiya. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LMAPlayerController.generated.h"

UCLASS()
class LEAVEMEALONE_API ALMAPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ALMAPlayerController();

protected:
	virtual void BeginPlay() override;

	virtual void BeginSpectatingState() override;

	
	

	//public:
	//UPROPERTY(EditDefaultsOnly, Category = "UI")
	//	TSubclassOf<UUserWidget> WBP_EndGameDeth; // Класс твоего виджета

	//UFUNCTION()
	//void ShowDeathMenu(); // Функция для отображения меню
};

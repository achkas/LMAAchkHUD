//  LeaveMeAlone Game by Netologiya. All Rights Reserved


#include "Player/LMAPlayerController.h"
#include "Blueprint/UserWidget.h"  // Базовый класс для виджетов
//#include "WBP_EndGameDeth.h"   // Заголовочный файл твоего виджета (если используешь кастомный класс)




ALMAPlayerController::ALMAPlayerController() {}

void ALMAPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}

void ALMAPlayerController::BeginSpectatingState()
{
	SetControlRotation(FRotator(-75.0f, 0.0f, 0.0f));
	Super::BeginSpectatingState();
	
}

//void ALMAPlayerController::BeginSpectatingState()
//{
//	SetControlRotation(FRotator(-75.0f, 0.0f, 0.0f));
//	Super::BeginSpectatingState();
//	
//
//	// Вызываем меню через 0.1 сек (на всякий случай, чтобы избежать гонки состояний)
//	FTimerHandle TimerHandle;
//	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALMAPlayerController::ShowDeathMenu, 0.1f, false);
//}
//
//void ALMAPlayerController::ShowDeathMenu()
//{
//	if (WBP_EndGameDeth)
//	{
//		UUserWidget* DeathWidget = CreateWidget<UUserWidget>(this, WBP_EndGameDeth);
//		if (WBP_EndGameDeth)
//		{
//			DeathWidget->AddToViewport(100);  // 100 — высокий Z-Order, чтобы был поверх всего
//			SetInputMode(FInputModeUIOnly()); // Переключаем ввод на UI
//			bShowMouseCursor = true;		  // Показываем курсор
//		}
//	}
//}
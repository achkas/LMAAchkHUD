//  LeaveMeAlone Game by Netologiya. All Rights Reserved


#include "Player/LMAPlayerController.h"
#include "Blueprint/UserWidget.h"  // ������� ����� ��� ��������
//#include "WBP_EndGameDeth.h"   // ������������ ���� ������ ������� (���� ����������� ��������� �����)




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
//	// �������� ���� ����� 0.1 ��� (�� ������ ������, ����� �������� ����� ���������)
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
//			DeathWidget->AddToViewport(100);  // 100 � ������� Z-Order, ����� ��� ������ �����
//			SetInputMode(FInputModeUIOnly()); // ����������� ���� �� UI
//			bShowMouseCursor = true;		  // ���������� ������
//		}
//	}
//}
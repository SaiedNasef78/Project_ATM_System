#pragma once
#include "clsInputValidate.h"
#include "global.h"
#include "clsClient.h"
#include <iomanip>
#include "clsDate.h"
#include "clsScreen.h"
#include "clsQuickWithdrawScreen.h"
#include "clsNormalWithdrawScreen.h"
#include "clsDepositScreen.h"
#include "clsCheackBalanceScreen.h"
class clsMainMenueScreen:protected clsScreen
{
private:
	enum enMainMenue {
		eQuickWithdraw = 1,
	eNormalWithdraw=2,
	eDeposit=3,
	eCheckBalance=4,
	Exist=5,
	};
	static short _ReadMainMeneuOption() {
		cout << left << setw(37) << "" << "Choose what do you want to do ? [1 to 5 ?\n";
		cout << left << setw(37) << "";
		return clsInputValidate::ReadNumberBetween<short>(1,5,"Invalid Number,enter again. ");


	}
	
	static void _ShowQickWithdrwaScreen() {

	//	cout << "\nQuick With drwa will be here....\n";
		clsQuickWithdrawScreen::ShowQuickWithDraw();
		
	}
	static void _ShowNormalWithdrawScreen() {
		//cout << "\nQuick With drwa will be here....\n";
		clsNormalWithdrawScreen::ShowNormalWithDrawScreen();
		
	}

	static void _ShowDepsitScreen() {

		//cout << "\nQuick With drwa will be here....\n";
		clsDepositScreen::ShowDepositScreen();
		

	}
	static void ShowCheckBalance() {
		clsCheackBalanceScreen::ShowCheckBalanceScreen();
		

	}

	static void _GoBackToMainMenue() {
		cout << "Press ony one to key.....\n";
		system("pause>0");
		

		ShowMainMenueScreen();

	}
	static void _PerformMainMenueOption(enMainMenue Option) {
		system("cls");
		switch (Option) {

		case enMainMenue::eQuickWithdraw:

		{
			_ShowQickWithdrwaScreen();
			break;
		}


		case enMainMenue::eNormalWithdraw:
		{
			_ShowNormalWithdrawScreen();
			break;
		}

		case enMainMenue::eDeposit:


		{
			_ShowDepsitScreen();
			break;



		}

		case enMainMenue::eCheckBalance:

		{
			ShowCheckBalance();
			break;
		}

		case enMainMenue::Exist:


		{
			break;
		}

		}
		/*if (enMainMenue::Exist != Option) {

			_GoBackToMainMenue();

		}*/


	}

	
	
	

public:

	static bool ShowMainMenueScreen() {
		enMainMenue Option;

		do {
			system("cls");
			clsScreen::_ShowHeaderScreen("ATM Main Menue Screen");

			cout << left << setw(37) << "" << "==============================================\n";
			cout << left << setw(38) << "" << "[1] Quick With Draw Screen. \n";
			cout << left << setw(38) << "" << "[2] Norma With Draw Screen. \n";
			cout << left << setw(38) << "" << "[3] Deposit Screen. \n";
			cout << left << setw(38) << "" << "[4] Check BalnceScreen. \n";
			cout << left << setw(38) << "" << "[5] LogOut. \n";
			cout << left << setw(37) << "" << "==============================================\n";

			 Option = (enMainMenue)_ReadMainMeneuOption();
			if (Option != enMainMenue::Exist) {
				_PerformMainMenueOption(Option);
				cout << "Press ony one to key.....\n";
				system("pause>0");


			}
		} while (Option != enMainMenue::Exist);
		return true;
	}


};


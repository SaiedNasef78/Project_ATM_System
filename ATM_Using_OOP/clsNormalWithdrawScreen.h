#pragma once
#include "clsScreen.h"
#include "global.h"
#include "clsInputValidate.h"
class clsNormalWithdrawScreen:protected clsScreen
{
private:
	static bool _CheackMultipleBalance(int Balance) {
		return (Balance % 5 == 0);
	}
	static int _ReadMultipleBalance() {
		int Withdraw = 0;
		do  {
			cout << "\nEnter an amount multiple of 5's ?";
			 Withdraw = clsInputValidate::ReadNumber<int>();



		} while (!_CheackMultipleBalance(Withdraw));
		return Withdraw;
	}

public:
	static void ShowNormalWithDrawScreen() {

		clsScreen::_ShowHeaderScreen("Normal With draw Screen");

		cout << "\nYour Balance Is: " << Client.AccountBalance << endl;
		int Withdraw = _ReadMultipleBalance();
		if (Withdraw >= Client.AccountBalance) {

			cout << "\nThe amount exceds your balance, make another choise.\n";
			return;

		}
		vector<clsClient> vClient = clsClient::LoadClientDataFromFile();
		


		if (Client.WithdrawScreen(Client.AccountNumber, Withdraw, vClient)) {

			cout << "\nDone Successfully New Balance is: " << Client.AccountBalance<< endl;

		}


	}

};


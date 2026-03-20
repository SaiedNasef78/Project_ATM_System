#pragma once
#include "clsScreen.h"
#include "clsClient.h"
#include "global.h"
#include "clsInputValidate.h"
class clsDepositScreen:protected clsScreen
{
public:
	static void ShowDepositScreen() {
		clsScreen::_ShowHeaderScreen("Deposit Screen");

		vector < clsClient> VClient = clsClient::LoadClientDataFromFile();

		cout << "\nYour Balance Is: " << Client.AccountBalance << endl;

		cout << "\nPlease Enter Ammount Number? ";
		int Ammount = clsInputValidate::ReadNumber<int>();

		char A = 'n';
		cout << "Do you wnat to deposit amount [y]/[n]";
		cin >> A;
		if (A == 'y' || A == 'Y')
		{
			
			if (Client.DepositScreen(Client.AccountNumber,Ammount, VClient)) {

				cout << "\nDone Successfully New Balance is: " << Client.AccountBalance << endl;
				return;
			}
			


		}


	}




};


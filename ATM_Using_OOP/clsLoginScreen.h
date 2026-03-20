#pragma once
#include "clsMainMenueScreen.h"
#include "clsScreen.h"
class clsLoginScreen:protected clsScreen
{

private:

	static  bool FindClientByAccountNumber(string PinCode, string AccountNumber) {
		vector<clsClient> vClient = clsClient::LoadClientDataFromFile();
		for (clsClient& C : vClient) {

			if ((C.AccountNumber == AccountNumber) && (PinCode == C.PinCode)) {
				Client = C;
				return true;
			}
		}

		return false;


	}

public:
	static bool Login() {
		short Trail = 3;
		bool LoginFailed = false;
		do {

			system("cls");
			clsScreen::_ShowHeaderScreen("Login Screen ");
			if (LoginFailed) {
				cout << "\nInvalid AccountNumber And Password\n";
			
				cout << "You have " << --Trail << " Trials to login. \n";

				if (Trail == 0) {
					cout << "\nYou are locked after 0 failed trials :-(";
					return false;
				}
			}
			cout << "Please Enter Account Number ? \n";
			string AccountNumber = clsInputValidate::ReadNumber<string>();
			cout << "\nPlease Enter Passward? \n";
			string PinCode = clsInputValidate::ReadNumber<string>();


			LoginFailed = !FindClientByAccountNumber(PinCode, AccountNumber);

			

		} while (LoginFailed);

		clsMainMenueScreen::ShowMainMenueScreen();
		return true;

	}



};


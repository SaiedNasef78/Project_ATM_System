#pragma once
#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputValidate.h"
#include "global.h"
#include <iomanip>
class clsQuickWithdrawScreen :protected clsScreen
{
private:
	enum enWithdrwa {
		en20 = 1,
		en50 = 2,
		en100 = 3,
		en200 = 4,
		en400 = 5,
		en600 = 6,
		en800 = 7,
		en1000 = 8,
		enExist = 9,


	};
	static short _ReadWithdrawOptions() {

		cout << left << setw(37) << "" << "Choose what do you want to do ? [1 to 9 ?\n";
		cout << left << setw(37) << "";
		return clsInputValidate::ReadNumberBetween<short>(1, 9, "Invalid Number,enter again. ");


	}

	static short _getQuickWithDraw(enWithdrwa WithdrawOption) {
		switch (WithdrawOption) {

		case enWithdrwa::en20:
			return 20;

		case enWithdrwa::en50:
			return 50;
		case enWithdrwa::en100:
			return 100;

		case enWithdrwa::en200:
			return 200;

		case enWithdrwa::en400:
			return 400;

		case enWithdrwa::en600:
			return 600;
		case enWithdrwa::en800:
			return 800;
		case enWithdrwa::en1000:
			return 1000;
		case enWithdrwa::enExist:
			return 9;



		}



	}

	static void _PerformWithDraw(enWithdrwa WithDraw) {
		short QuickWithDraw = _getQuickWithDraw(WithDraw);

		if (WithDraw == enWithdrwa::enExist) {
			return;
		}
		if (QuickWithDraw >= Client.AccountBalance)

		{
			cout << "\nThe amount exceds your balance, make another choise.";
			cout << "\nPress any key countinue....";
			system("pause>0");
			ShowQuickWithDraw();
			return;
		}
		vector <clsClient> vClient = clsClient::LoadClientDataFromFile();


		char A = 'n';
		cout << "Do you wnat to With Draw amount[y] / [n] ";
		cin >> A;
		if (A == 'y' || A == 'Y')
		{

			if (Client.WithdrawScreen(Client.AccountNumber,QuickWithDraw, vClient)) {

				cout << "\n Done Successfully New Balance Is : " << Client.AccountBalance << endl;
			}

		}
			



		
	}

public:
	static void ShowQuickWithDraw() {

		clsScreen::_ShowHeaderScreen("Quick With Draw Screen");
	
		cout << left << setw(37) << "" << "==============================================\n";
		cout << left << setw(38) << "" << "[1]:20\t\t\t[2]:50. \n";
		cout << left << setw(38) << "" << "[3]:100\t\t\t[4]:200\n";
		cout << left << setw(38) << "" << "[5]:400\t\t\t[6]:600 \n";
		cout << left << setw(38) << "" << "[7]:800\t\t\t[8]:1000 \n";
		cout << left << setw(38) << "" << "[9] LogOut. \n";
		cout << left << setw(37) << "" << "==============================================\n";
		cout << left << setw(38) << "" << "Account Balance: " << Client.AccountBalance << endl;
		_PerformWithDraw((enWithdrwa)_ReadWithdrawOptions());

	}
};


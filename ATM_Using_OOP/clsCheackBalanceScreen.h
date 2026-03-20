#pragma once
#include "clsScreen.h"
#include "global.h"
class clsCheackBalanceScreen:protected clsScreen
{

public:
	static void ShowCheckBalanceScreen() {

		clsScreen::_ShowHeaderScreen("Check Balance Sceen");

		cout << "\n______________________________________\n\n";
		cout << "Your Balance Is: " << Client.AccountBalance << endl << endl;
		cout << "______________________________________\n\n";



	}



};


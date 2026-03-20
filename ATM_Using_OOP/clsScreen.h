#pragma once
#include <iomanip>
#include <iostream>
#include "clsDate.h"
#include "global.h"
using namespace std;
class clsScreen
{

protected:

	static void _ShowHeaderScreen(string Title, string subtitle = "") {

		cout << left << setw(37) << "" << "===========================================\n\n";
		cout << left << setw(45) << "" << Title << "\n\n";
		cout << left << setw(37) << "" << "===========================================\n\n";
		if (subtitle != "") {
			cout << left << setw(45) << "" << subtitle << "\n\n";

			cout << left << setw(37) << "" << "===========================================\n\n";
		}


		cout << left << setw(45) << "" << "Date: " << clsDate::DateToString(clsDate()) << "\n";
		cout << left << setw(45) << "" << "Client Name: " << Client.Name << "\n";

		cout << left << setw(37) << "" << "===========================================\n\n";
	}
	

};


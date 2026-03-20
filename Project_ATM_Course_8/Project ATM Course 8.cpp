// Project ATM Course 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Delete.h"
#include "Client.h"
#include <fstream>
using namespace std;
const string FileName = "MyFile.text";

MyClient::StClient Client;
enum enWithDrawQuick {
	ch1=1,
	ch2=2,
	ch3=3,
	ch4=4,
	ch5=5,
	ch6=6,
	ch7=7,
	ch8=8,
	Exite =9

};
enum enMainMenue {
	eQuickWithDraw=1,
	eNormalWithDraw=2,
	eDepost=3,
	eCheckBalance=4,
	LogOut=5
};
void ShowAtmMainMenue();
void Login();
void ShowQuickWithDraw();
void GoBackToMainMenue() {
	cout << "Press any key to go back to main menue...";
	system("pause>0");
	
	ShowAtmMainMenue();
}



short getQuickWithDarw(short  WithDarwQuick) {

	switch (WithDarwQuick) {

	case 1:
		return 20;
	case 2:
		return 50;
	case 3:
		return 100;
	case 4:
		return 200;
	case 5:
		return 400;
	case 6:
		return 600;
	case 7:
		return 800;
	case 8:
		return 1000;
	default:
		return 0;
			








	}





}
void PlatformToWithDarw(short  WithDarwQuick) {
	
		
	if (WithDarwQuick == 9) {
		return;
	}
	short QuickWithDarw = getQuickWithDarw(WithDarwQuick);
		
		if (QuickWithDarw >= Client.AccountBalance) {
			cout << "\nThe amount exceds your balance, make another choise.";
			cout << "\nPress anykey countinue....";
			system("pause>0");
			ShowQuickWithDraw();
			return;

		}
		vector<MyClient::StClient> Vec = MyClient::LoadClientDataFromFile();
		if (!MyD::DepostAccountBalance(Client.AccountNumber, QuickWithDarw * -1, Vec)) {
			return;
		}
		Client.AccountBalance = Client.AccountBalance- QuickWithDarw;

		cout << "\n Done Successfully New Balance Is : " << Client.AccountBalance << endl;
}

short ReadchooseWithDraw() {
	short ch=0;
	while (ch < 1 || ch>9) {
		cout << "Choose what to withdraw from[1] to [9] ?";
		cin >> ch;
	}
	
	return ch;

}
void ShowQuickWithDraw() {
	system("cls");
	cout << "========================================\n";
	cout << "\t\tQuick WithDraw\n";
	cout << "========================================\n";
	cout << "\t[1] 20\t\t[2] 50\n";
	cout << "\t[3] 100\t\t[4] 200\n";
	cout << "\t[5] 400\t\t[6] 600\n";
	cout << "\t[7] 800\t\t[8] 1000\n";
	cout << "\t[9] Exite\n";
	cout << "========================================\n";
	cout << "Your Balance is " << Client.AccountBalance << endl;

	
	PlatformToWithDarw(ReadchooseWithDraw());

}
short ReadMainMenue() {
	short ch;
	cout << "Choose what do you want to do?[1 to 5?";
	cin >> ch;
	return ch;

}
bool CheackAmountMultiple(int Balance) {
	return  ((Balance % 5 == 0));
	
}
int ReadWithDarw() {

	int  WithDraw;
	cout << "\nEnter an amount multiple of 5's ?";
	cin >> WithDraw;

	while (!CheackAmountMultiple(WithDraw)) {
		cout << "\nEnter an amount multiple of 5's ?";
		cin >> WithDraw;


	}
	return WithDraw;
}
void ShowWithDrawScreen() {


	cout << "\nYour Balnce is: " << Client.AccountBalance << endl;
	int WithDraw = ReadWithDarw();
	
	if (WithDraw >= Client.AccountBalance) {
		cout << "\nThe amount exceds your balance, make another choise.";
		GoBackToMainMenue();

	}
	vector<MyClient::StClient> Vec = MyD::LoadClintDataFromFile();
	Client.AccountBalance -= WithDraw;

	if (MyD::DepostAccountBalance(Client.AccountNumber, WithDraw * -1, Vec)) {
		cout << "\nDone Successfully New Balance is: " << Client.AccountBalance << endl;
	}
	/*Client.AccountBalance -= WithDraw;*/
	


}
void ShowNormalWithDraw() {
	system("cls");
	cout << "=============================================\n";
	cout << "\t\tNormal WithDraw Screen\n";
	cout << "=============================================\n";
	ShowWithDrawScreen();
}
double ReadPositiveAmmount() {
	double Ammount;
	do {

		cout << "\nEnter a positive ammount ? ";
		cin >> Ammount;

	} while (Ammount <= 0);


	return Ammount;
}
void PlatformDepost(double Ammount) {

	vector<MyClient::StClient> Vec = MyD::LoadClintDataFromFile("MyFile.text");
	if (!MyD::DepostAccountBalance(Client.AccountNumber, Ammount, Vec)) {
		return;
	}
	
	Client.AccountBalance += Ammount;
	cout << "\n Done Successfully New Balance Is : " << Client.AccountBalance << endl;
}
void ShowDepostClientBalnce() {
	
	cout << "========================================\n";
	cout << "\t\tDepost Screen\n";
	cout << "========================================\n";
	
	PlatformDepost(ReadPositiveAmmount());
	
}
void showCheckBalance() {
	system("cls");
	cout << "======================================\n";
	cout << "\t\tCheck Balance Screen\n";
	cout << "======================================\n";
	cout << "Your Balance is " << Client.AccountBalance << endl;
}
void PlatformToMainMenue(enMainMenue MenueScreen) {

	switch (MenueScreen) {

	case enMainMenue::eQuickWithDraw:
		system("cls");
		ShowQuickWithDraw();
		GoBackToMainMenue();
		break;
	case enMainMenue::eNormalWithDraw:
		system("cls");
		ShowNormalWithDraw();
		GoBackToMainMenue();
		break;
	case enMainMenue::eDepost:
		system("cls");
		ShowDepostClientBalnce();
		GoBackToMainMenue();
		break;
	case enMainMenue::eCheckBalance:
		system("cls");
		showCheckBalance();
		GoBackToMainMenue();
		break;
		
	case enMainMenue::LogOut:
		system("cls");
		Login();
		break;
	}



}
void ShowAtmMainMenue() {
	system("cls");
	cout << "========================================\n";
	cout << "\t\tATM Main Menue Screen\n";
	cout << "========================================\n";
	    cout << "\t[1] Quick Withdraw.\n";
		cout << "\t[2] Normal Withdraw.\n";
		cout << "\t[3] Depost.\n";
		cout << "\t[4] Cheack Balance.\n";
		cout << "\t[5] LogOut.\n";
	cout << "========================================\n";
	PlatformToMainMenue((enMainMenue)ReadMainMenue());
}
bool LoadClinetInfo(string AccountNumber, string PinCode, vector<MyClient::StClient> Vec) {

	return (!MyD::FindAccountNumberByClient(AccountNumber, Client, Vec));

}
void Login() {
	vector<MyClient::StClient> Vec = MyD::LoadClintDataFromFile();

	bool LoginFaild = false;
	string AccountNumber;
	string PinCode;
	cout << "\n--------------------------\n";
	cout << "\tLogin Screen \n";
	cout << "---------------------------\n";
	do {

		if (LoginFaild) {
			cout << "Invlaid Account Number/PinCode\n";
		}

		cout << "Enter Account Number? ";
		cin >> AccountNumber;
		cout << "\nEnter PinCode? ";
		cin >> PinCode;
		LoginFaild = LoadClinetInfo(AccountNumber, PinCode, Vec);


	} while (LoginFaild);

	ShowAtmMainMenue();





}
int main()
{
	Login();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

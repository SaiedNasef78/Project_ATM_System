#pragma once
// c  p 45.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class clsClient
{
private:
   
            string _AccountNumber;
            string _PinCode;
            string _Name;
            string _Phone;
            double _AccountBalance;
            bool _MarkForDelete = false;
       
       static clsClient _ReadClientData(string A) {
            clsClient Client;

            Client._AccountNumber = A;
            cout << "\nEnter Pin Code ? ";
            getline(cin >> ws, Client._PinCode);
            cout << "\nEnter Your Name ? ";
            getline(cin, Client._Name);
            cout << "\nEnter Your Phone ?  ";
            getline(cin, Client._Phone);
            cout << "\nEnter Account Balance ? ";
            cin >> Client._AccountBalance;

            return Client;


        }
      static  vector<string>_SpliteVector(string S, string Seperator) {

            short pos = 0;
            vector<string> Vec;
            string SWord;
            while ((pos = S.find(Seperator)) != std::string::npos)
            {
                SWord = S.substr(0, pos);
                if (SWord != "") {

                    Vec.push_back(SWord);
                }
                S.erase(0, pos + Seperator.length());




            }
            if (S != "") {

                Vec.push_back(S);
            }



            return Vec;



        }
     static  clsClient _ConvertLineToObject(string Line) {
          vector<string> Vec = _SpliteVector(Line, "#//#");
          clsClient Client;
          Client.AccountNumber = Vec[0];
          Client.PinCode = Vec[1];
          Client.Name = Vec[2];
          Client.Phone = Vec[3];
          Client._AccountBalance = stod(Vec[4]);


          return Client;


      }
     static void _SaveDateToFile(vector<clsClient> vClient) {

         fstream MyFile;
         MyFile.open("MyFile.text", ios::out);
         if (MyFile.is_open()) {

             for (clsClient& C : vClient) {
                 string Line = ConvertObjectToLine(C);
                 if (C._MarkForDelete == false) {

                     MyFile << Line << endl;

                 }


             }

             MyFile.close();


         }


}
public :
    clsClient() {

    }

    clsClient(string AccountNumber, string PinCode, string Name, string Phone, double AccountBalance, bool Marfordelete) {
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _Name = Name;
        _Phone = Phone;
        _AccountBalance = AccountBalance;
        _MarkForDelete = Marfordelete;

    }
    //write only
    void setAccountNumber(string AccountNumber) {
        _AccountNumber = AccountNumber;
    }
    // ReadOnly 
    string getAccountNumber() {
        return _AccountNumber;
    }
    __declspec(property(get = getAccountNumber, put = setAccountNumber)) string AccountNumber;

    void setPinCode(string PinCode) {
        _PinCode = PinCode;
    }
    string getPinCode() {
        return _PinCode;
    }
    __declspec(property(get = getPinCode, put = setPinCode)) string PinCode;

    void setName(string Name) {
        _Name = Name;
    }
    string getName() {
        return _Name;
    }
    __declspec(property(get = getName, put = setName)) string Name;


    void setPhone(string Phone) {
        _Phone = Phone;
    }

    string getPhone() {
        return _Phone;
    }
    __declspec(property(get = getPhone, put = setPhone)) string Phone;

    void setAccountBalance(double Balance) {

        _AccountBalance = Balance;
    }
    // readonly
    double getAccountBalance() {
        return _AccountBalance;
    }
    __declspec(property(get = getAccountBalance, put = setAccountBalance)) double AccountBalance;


    static  string ConvertObjectToLine(clsClient Client, string Seperator = "#//#") {

        string Sword = "";
        Sword += Client.AccountNumber + Seperator;
        Sword += Client.PinCode + Seperator;
        Sword += Client.Name + Seperator;
        Sword += Client.Phone + Seperator;
        Sword += to_string(Client._AccountBalance);
        return Sword;
    }


    static    vector<clsClient> LoadClientDataFromFile(string CFileName = "MyFile.text") {
        vector<clsClient> Vec;
        fstream MyFile;
        MyFile.open(CFileName, ios::in);
        if (MyFile.is_open()) {

            string Line;
            clsClient Client;
            while (getline(MyFile, Line)) {
                Client = _ConvertLineToObject(Line);
                Vec.push_back(Client);




            }
            MyFile.close();



        }


        return Vec;



    }

   /*bool DepositScreen( string  AccountNumber, double Ammount, vector<clsClient>& Vclient, string Message = "Do you wnat to deposit amount [y]/[n]") {

        char A = 'n';
        cout << Message;
        cin >> A;
        if (A == 'y' || A == 'Y')
        {
            for (clsClient& C : Vclient)
            {
                if (AccountNumber == C.AccountNumber)

                {

                    C._AccountBalance += Ammount;
                    *this = C;
                    _SaveDateToFile(Vclient);
                    Vclient = LoadClientDataFromFile();
                    return true;
                }
            }


        }
        return false;
    }*/
    bool DepositScreen(string AccountNumber,double Ammount, vector<clsClient>& Vclient) {
       
       
        for (clsClient& C : Vclient) {

            if (AccountNumber == C.AccountNumber) {
                C.AccountBalance += Ammount;
                *this = C;
              
                _SaveDateToFile(Vclient);
               
                Vclient = LoadClientDataFromFile();
               
                return true;
            }

        }

        
        return false;
    }
    bool WithdrawScreen(string AccountNumber, double Ammount, vector<clsClient>& Vclient){

        return  DepositScreen(AccountNumber,Ammount*-1, Vclient);
       


     }
  

};


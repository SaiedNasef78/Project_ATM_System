#pragma once

#include <iostream>
#include <string>
#include<vector>
#include<fstream>
#include"Client.h"
    using namespace std;
    
    namespace MyD {
        vector<MyClient::StClient> LoadClintDataFromFile(string FileName = "MyFile.text") {

            fstream MyFile;

            vector< MyClient::StClient> VClient;
            MyFile.open(FileName, ios::in);
            if (MyFile.is_open()) {
                string Line;

                MyClient::StClient Client;
                while (getline(MyFile, Line)) {
                    Client = MyClient::ConvertToLine(Line);
                    VClient.push_back(Client);
                }
            }
            return VClient;
        }
        double ReadAccountBalance() {
            double P;
            cout << "\nPLease Enter Depost Account Balance ";
            cin >> P;
            return P;
        }


        bool FindAccountNumberByClient(string AccountNumber, string PinCode, MyClient::StClient& Client, vector<MyClient::StClient> VClient) {

            for (MyClient::StClient& C : VClient) {

                if ((C.AccountNumber == AccountNumber) && (C.PinCode == PinCode)) {

                    Client = C;

                    return true;

                }


            }
            return false;

        }

        bool FindAccountNumberByClient(string AccountNumber, MyClient::StClient& Client, vector<MyClient::StClient> VClient) {

            for (MyClient::StClient& C : VClient) {

                if ((C.AccountNumber == AccountNumber)) {

                    Client = C;

                    return true;

                }


            }
            return false;

        }

        string ReadAccountNumber() {

            string s;
            cout << "Please Enter Account Number ? ";
            cin >> s;
            return s;

        }

        void AddClient(MyClient::StClient Client) {
            cout << "_-------------------------------------------------------------";
            cout << "\n\n Account Number : " << Client.AccountNumber << endl;
            cout << "Pin Code			 : " << Client.PinCode << endl;
            cout << "Name			     : " << Client.Name << endl;
            cout << "Phone				 : " << Client.Phone << endl;
            cout << "AccountBalance      : " << Client.AccountBalance;
            cout << "\n\n-------------------------------------------------------------";


        }
        void SaveClientToFile(vector<MyClient::StClient> VClient) {

            fstream MyFile;

            MyFile.open("MyFile.text", ios::out);
            if (MyFile.is_open()) {
                string Line;
                for (MyClient::StClient C : VClient) {
                    if (C.MarkForDelete == false) {
                        Line = MyClient::ConvertRecordToLine(C, "#//#");


                        MyFile << Line << endl;



                    }

                }

                MyFile.close();

            }

        }
        bool MarkFile(string AccountNumber, vector<MyClient::StClient>& VClient) {

            for (MyClient::StClient& C : VClient) {
                if (AccountNumber == C.AccountNumber) {

                    C.MarkForDelete = true;
                    return true;
                }


            }
            return false;




        }
        bool DeleteClientFromFile(string AccountNumber, vector<MyClient::StClient>& VClient, MyClient::StClient& Client) {
            char Answer = 'y';
            if (FindAccountNumberByClient(AccountNumber, Client, VClient)) {
                AddClient(Client);

                cout << "\n Do You Want To Delete File \n";
                cin >> Answer;
                if (Answer == 'y' || Answer == 'Y') {

                    MarkFile(AccountNumber, VClient);
                    SaveClientToFile(VClient);
                    VClient = LoadClintDataFromFile();

                    cout << "\n Deleted Succesfuly";

                    return true;
                }



            }
            else
            {
                cout << "\n Not Found Account Number ";
                return false;
            }
        }
        bool DepostAccountBalance(string  AccountNumber,double Ammount, vector< MyClient::StClient>& VClient) {
          //  double TotalBalnce;
            
            char A = 'y';
            cout << "\nDo You Want depost Account Balance ?\n";
            cin >> A;
            if (A == 'y' || A == 'Y') {
                for (MyClient::StClient& C : VClient) {
                    if (AccountNumber == C.AccountNumber) {

                        C.AccountBalance += Ammount;
                        SaveClientToFile(VClient);
                        VClient = LoadClintDataFromFile();
                       
                        return true;
                    }
                }
            }
            return false;

        }

    


        
        bool WithDrawAccountBalance(string  AccountNumber, MyClient::StClient& Client, vector< MyClient::StClient>& VClient) {
            char A = 'y';
            while (!FindAccountNumberByClient(AccountNumber, Client, VClient)) {

                cout << "\n Client With [ " << AccountNumber << "] does not exist.";
                //cout << "\nPlease Enter Account Number ? ";
                AccountNumber = ReadAccountNumber();

            }
            AddClient(Client);

            double P = ReadAccountBalance();
            cout << "\nDo You Want WithDraw Account Balance ?\n";
            cin >> A;
            if (A == 'y' || A == 'Y') {

                for (MyClient::StClient& C : VClient) {
                    if (C.AccountNumber == AccountNumber) {
                        C.AccountBalance -= P;
                        break;
                    }

                }
                SaveClientToFile(VClient);
                //  VClient = MyD::LoadClintDataFromFile();

                cout << "\n Updated Succesfuly";
            }
            return true;


        }

    }
    
    
    


#pragma once
#include <iostream>
#include <string>
#include<vector>
using namespace std;
#include"Client.h"
#include"Delete.h"
namespace Upadte {

    bool FindAccountNumberByClient(string AccountNumber, MyClient::StClient& Client, vector<MyClient::StClient> VClient) {

        for (MyClient::StClient& C : VClient) {

            if (C.AccountNumber == AccountNumber) {

                Client = C;

                return true;

            }


        }
        return false;


    }

    bool UbdatedClientFromFile(string AccountNumber, vector<MyClient::StClient>& VClient, MyClient::StClient& Client) {
        char Answer = 'y';
        if (FindAccountNumberByClient(AccountNumber, Client, VClient)) {
           MyD:: AddClient(Client);

            cout << "\n Do You Want To Delete File \n";
            cin >> Answer;
            if (Answer == 'y' || Answer == 'Y') {

                for (MyClient::StClient& C : VClient) {
                    if (C.AccountNumber == AccountNumber) {
                      C=  MyClient::ReadClientData(AccountNumber);
                    }

              }
               MyD:: SaveClientToFile(VClient);
                VClient = MyD::LoadClintDataFromFile();

                cout << "\n Updated Succesfuly";
              
                return true;
            }
            else
            {

                return false;
            }

        }
        else
        {
            cout << "\n Not Found Account Number ";
           
            return false;
        }



    }









}
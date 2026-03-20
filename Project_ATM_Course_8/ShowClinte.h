#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<iomanip>
#include<fstream>
#include"Client.h"

const string ShFileName = "MyFile.text";
namespace MyShow {
    MyClient::StClient ConvertRecordToLine(string Line) {
        vector<string> Vec;
        MyClient::StClient Client;
        Vec = MyClient::SpliteVector(Line, "#//#");
        Client.AccountNumber = Vec[0];
        Client.PinCode = Vec[1];
        Client.Name = Vec[2];
        Client.Phone = Vec[3];
        Client.AccountBalance = stod(Vec[4]);


        return Client;
    }

    vector< MyClient::StClient> LoadClientDataFromFile() {
        vector<MyClient::StClient> Vec;
        fstream MyFile;
        MyFile.open(ShFileName, ios::in);
        if (MyFile.is_open()) {
            string Line;
            MyClient::StClient Client;
            while (getline(MyFile, Line)) {
                Client = ConvertRecordToLine(Line);
                Vec.push_back(Client);




            }
            MyFile.close();



        }


        return Vec;



    }
    void AddClint(MyClient::StClient Client) {


        cout << "\n| " << left << setw(14) << Client.AccountNumber;
        cout << "| " << left << setw(12) << Client.PinCode;
        cout << "| " << left << setw(40) << Client.Name;
        cout << "| " << left << setw(15) << Client.Phone;
        cout << "| " << left << setw(15) << Client.AccountBalance;



    }
    void AddClients(vector< MyClient::StClient> Vec) {
        cout << "\n_______________________________________________________________________\n";
        cout << "\t\t\t\t\t Clints Size(" << Vec.size() << ")\t\t\t\t\t\n";
        cout << "_______________________________________________________________________ \n\n";

        cout << "\n| " << left << setw(14) << "AccountNumber";
        cout << "| " << left << setw(12) << "PinCode";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(15) << "Phone";
        cout << "| " << left << setw(15) << "AccountBalance";

        for (MyClient::StClient& s : Vec)
        {
            AddClint(s);

        }



    }
}
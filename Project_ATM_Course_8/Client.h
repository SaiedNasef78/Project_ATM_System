#pragma once
// c  p 45.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

namespace MyClient {
    struct StClient {
        string AccountNumber;
        string PinCode;
        string Name;
        string Phone;
        double AccountBalance;
        bool MarkForDelete = false;
    };
    StClient ReadClientData(string A) {
        StClient Client;
        
         Client.AccountNumber=A;
        cout << "\nEnter Pin Code ? ";
        getline(cin>>ws, Client.PinCode);
        cout << "\nEnter Your Name ? ";
        getline(cin, Client.Name);
        cout << "\nEnter Your Phone ?  ";
        getline(cin, Client.Phone);
        cout << "\nEnter Account Balance ? ";
        cin >> Client.AccountBalance;

        return Client;


    }
    string ConvertRecordToLine(StClient Client, string Seperator) {

        string Sword = "";
        Sword += Client.AccountNumber + Seperator;
        Sword += Client.PinCode + Seperator;
        Sword += Client.Name + Seperator;
        Sword += Client.Phone + Seperator;
        Sword += to_string(Client.AccountBalance);
        return Sword;
    }
   
    vector<string>SpliteVector(string S, string Seperator) {

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
    StClient ConvertToLine(string Line ) {
        vector<string> Vec = SpliteVector(Line, "#//#");
        StClient Client;
        Client.AccountNumber = Vec[0];
        Client.PinCode = Vec[1];
        Client.Name = Vec[2];
        Client.Phone = Vec[3];
        Client.AccountBalance = stod(Vec[4]);


        return Client;


    }
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

    vector< MyClient::StClient> LoadClientDataFromFile(string CFileName = "MyFile.text") {
        vector<MyClient::StClient> Vec;
        fstream MyFile;
        MyFile.open(CFileName, ios::in);
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
   
}
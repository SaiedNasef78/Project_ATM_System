#pragma once
#include <iostream>
#include "clsDate.h"
#include "clsString.h"
using namespace std;

class clsInputValidate
{
	
public:
	template<typename T>
	static bool IsNumberBetween(T Num, T From, T To) {

		return (Num >= From && Num <= To);

	}
	//template<typename T>
	static bool IsDateBetween(clsDate D, clsDate From, clsDate To) {
		
		if ((clsDate::IsDate1EqualDate2(D, From) || clsDate::IsDate1AfterDat2(D, From)) && (clsDate::IsDate1BeforeDate2(D, To) || clsDate::IsDate1EqualDate2(D, To))) {
			
				return true;
			}
		
		if  ((clsDate::IsDate1EqualDate2(D, To) || clsDate::IsDate1AfterDat2(D,To)) && (clsDate::IsDate1BeforeDate2(D, From) || clsDate::IsDate1EqualDate2(D, From)))
		{
			return true;
		}
		return false;
	}
	template<typename t>
	static t ReadNumber(string ErrorMessage="Invalid Number,enter again? ") {
		t num;
		
		while (!(cin>>num)) {
			cin.clear();
			cin.ignore(numeric_limits < streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
			


		}
		return num;

	}
	template<typename T>
	static T ReadNumberBetween(T from, T to, string Meassage) {
		T num;
		num = ReadNumber<T>();
		while (!IsNumberBetween(num, from, to)) {
			cout << Meassage << endl;
			
			num = ReadNumber<T>();
		}
		return num;
	}
	//template<typename T>
	
	static void IsValidDate(clsDate d) {
		if (d.IsValidateDate(d)) {
			cout << "\n\nYes, Is a validate Date";
		}
		else {

			cout << "\n\nNo, Is a Not validate Date";

		}
	}


};


#pragma once
#include <iostream>
#include <vector>
using namespace std;
class clsString
{
private:
	string _Value;
	
	

	
	
public:
	clsString() {
		_Value = "";
	}
	clsString(string Value) {
		_Value = Value;
	}
	void SetValue(string Value) {
		_Value = Value;
	}
	string getValue() {
		return _Value;
	}

	__declspec(property(get = getValue, put = SetValue)) string Value;
	// return Number Of Words;
	static short CountWords(string S1) {
		short pos = 0;
		string delim = " ";
		string words; 
		short Counter = 0;
		while ((pos = S1.find(delim)) != std::string::npos) {
			words = S1.substr(0, pos);
			if (words != " ") {
				Counter++;
			}

			S1.erase(0, pos + delim.length());



		}
		if (S1 != " ") {
			Counter++;
		}
		return Counter;
	}
	short CountWords() {
		return CountWords(_Value);
	}

	// Print First Latter From Word
	 static void PrintFirstLatter(string Meassage) {
		bool IsFirstLatter = true;
		for (int i = 0; i < Meassage.size(); i++) {
			if (Meassage[i] != ' ' && IsFirstLatter) {

				cout << Meassage[i] << "  ";

			}
			IsFirstLatter = (Meassage[i] == ' ') ? true : false;



		}
	}
	void PrintFirstLatter() {
		PrintFirstLatter(_Value);
	}
	//UPerr FirstLatter
	static string  UperrFirstLatterEachWord(string s1) {
		bool IsFirstLatter = true;
		for (int i = 0; i < s1.size(); i++) {

			if (s1[i] != ' ' && IsFirstLatter) {

				s1[i] = toupper(s1[i]);

			}
			IsFirstLatter = (s1[i] == ' ') ? true : false;

		}

		return s1;



	}
	void UperrFirstLatterEachWord() {
		_Value =UperrFirstLatterEachWord(_Value);
		
	 }
	//Print Lower First Capital Latter
	static string LowerFirstCapitalLatter(string s1) {
		bool IsFirstLatter = true;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != ' ' && IsFirstLatter) {

				s1[i] = tolower(s1[i]);

			}
			IsFirstLatter = (s1[i] == ' ') ? true : false;


		}


		return s1;

	}
	void LowerFirstCapitalLatter() {
		_Value= LowerFirstCapitalLatter(_Value);
		
	}
	//print All Words UPPER 
	 static string UpperCapitalLatter(string s1) {

		for (int i = 0; i < s1.size(); i++) {
			s1[i] = toupper(s1[i]);


		}

		return s1;
	}
	void  UpperCapitalLatter() {
		_Value= 	 UpperCapitalLatter(_Value);
		
	}
	//print All Words Lower
	static string lowerSmallLatter(string s1) {

		for (int i = 0; i < s1.size(); i++) {
			s1[i] = tolower(s1[i]);


		}

		return s1;
	}
	void  lowerSmallLatter() {
		_Value = lowerSmallLatter(_Value);
	}

	
	
	//Convert Small Latter To Cpital Ltter And Reverse
	static char InvertAllLatterCase(char s1) {

		return isupper(s1) ? tolower(s1) : toupper(s1);

	}
	static string InvertAllLatter(string s1) {
		for (int i = 0; i < s1.size(); i++) {
			s1[i] = InvertAllLatterCase(s1[i]);
		}

		return s1;
	}
void   InvertAllLatter() {
		_Value= InvertAllLatter(_Value);

	}
	enum enWhatToCount { CapitalLatter = 0, SmallLatter = 2, All = 3 };
	
	static short CountLatter(string s1, enWhatToCount WhatToCount = enWhatToCount::All) {

		int Count = 0;
		for (int i = 0; i < s1.size(); i++) {
			if (WhatToCount == enWhatToCount::All)
			
				return s1.size();
			
			if (WhatToCount == enWhatToCount::CapitalLatter && isupper(s1[i]))

				Count++;

			if (WhatToCount == enWhatToCount::SmallLatter && islower(s1[i]))
				Count++;

		}

		return Count;



	}
	short CountLatter(enWhatToCount WhatToCount = enWhatToCount::All) {

		return CountLatter(_Value, WhatToCount);
	}
	static int CalcolateCapitalCount(string& s1) {
		int Count = 0;
		for (int i = 0; i < s1.size(); i++) {
			if (isupper(s1[i]))
			{
				Count++;

			}


		}

		return Count;
	}
	int  CalcolateCapitalCount() {
		return  CalcolateCapitalCount(_Value);
	}
	static int CalculateSmallLatter(string& s1) {
		int Count = 0;
		for (int i = 0; i < s1.size(); i++) {
			if (islower(s1[i]))
			{
				Count++;

			}


		}

		return Count;
	}
	int CalculateSmallLatter() {
		return CalculateSmallLatter(_Value);

	}


	static int CountCharctringToString(string s1, char ch1) {
		int Count = 0;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] == ch1) {
				Count++;

			}



		}
		return Count;

	}
	int CountCharctringToString(char ch1) {


		return CountCharctringToString(_Value, ch1);
	}
	static bool IsVowelLatter(char ch1) {
		ch1 = tolower(ch1);
		return (ch1 == 'a' || ch1 == 'u' || ch1 == 'i' || ch1 == 'o' || ch1 == 'e');

	}
	static short CountAllVewoel(string S1) {
		short Count = 0;
		for (int i = 0; i < S1.size(); i++) {
			if (IsVowelLatter(S1[i]))
			{

				Count++;

			}


		}

		return Count;

	}

short CountAllVewoel() {
	return CountAllVewoel(_Value);

}


void PrintAllVewoel(string S1) {
	cout << "\n\n  Veowls In String Are : ";
	for (int i = 0; i < S1.size(); i++) {
		if (IsVowelLatter(S1[i]))
		{

			cout << S1[i] << "  ";

		}


	}



}
void  PrintAllVewoel() {

	PrintAllVewoel(_Value);
	
}

void PrintEachWords(string S1) {
	bool IsFirstLatter = true;
	cout << "\n\n Your String Are : \n";
	for (int i = 0; i < S1.size(); i++) {
		if (S1[i] != ' ' && IsFirstLatter) {

			cout << endl;

		}
		IsFirstLatter = (S1[i] == ' ') ? true : false;
		cout << S1[i];

	}



}
void PrintEachWords() {
	PrintEachWords(_Value);
}

short CountEachWords(string S1) {
	short Count = 0;
	string delim = " ";
	short Pos = 0;
	string Sword;
	while ((Pos = S1.find(delim)) != std::string::npos) {
		Sword = S1.substr(0, Pos);

		if (Sword != "") {

			Count++;

		}


		S1.erase(0, Pos + delim.length());



	}
	if (S1 != "") {


		Count++;
	}
	return Count;
}

short CountEachWords() {

return	CountEachWords(_Value);
}

static vector <string> Splite(string S1, string delim=" ") {
	short pos = 0;
	vector <string> vString;
	string Sword;
	while ((pos = S1.find(delim)) != std::string::npos) {

		Sword = S1.substr(0, pos);
		if (Sword != "") {

			vString.push_back(Sword);

		}
		S1.erase(0, pos + delim.length());

	}

	if (S1 != " ") {

		vString.push_back(S1);

	}
	return vString;
}
void PrintVector(vector<string> sword) {

	for (string g : sword) {

		cout << g << endl;


	}



}

void PrintVector() {

	PrintVector(Splite(_Value));



}
static string TrimLift(string S) {
	string word;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] != ' ') {
			return (S.substr(i, S.size()));
		}
	}
	

}
void TrimLift() {
	_Value=  TrimLift(_Value);
}
static string TrimRight(string S) {

	for (int i = S.size() - 1; i > 0; i--) {
		if (S[i] != ' ') {


			return (S.substr(0, i));




		}


	}


}
void TrimRight() {
	_Value =  TrimRight(_Value);

}
static short Length(string S) {
	return S.length();
}
 short Length() {
	 return Length(_Value);
 }
void Trim() {

	_Value=(TrimLift(TrimRight(_Value)));
}
static string JoinString(vector<string>Vjoin, string delim = ",") {
	string Sword;

	for (string& S : Vjoin) {

		Sword = Sword + S + delim;

	}



	return Sword.substr(0, Sword.length() - delim.length());

}
static string JoinString(string Arr[3], short  length, string Delim=" ") {
	string Sword = "";
	for (int i = 0; i <length; i++) {

		Sword += Arr[i] + Delim;

	}
	return (Sword.substr(0, Sword.size() - Delim.size()));

}
static string ReverseInWordsString(string S) {
	vector<string> Vec = Splite(S, " ");
	string s = "";
	vector<string>::iterator iter = Vec.end();
	while (iter != Vec.begin()) {

		iter--;
		s += *iter + " ";


	}
	//s += s.substr(0, S.size() - 1);
	return s;
}
void ReverseInWordsString() {
	_Value = ReverseInWordsString(_Value);
}

string ReplaceInwordsBuildInFunction(string S, string ReplaceTo, string Replace) {
	short pos = S.find(ReplaceTo);

	while (pos != std::string::npos) {

		S = S.replace(pos, ReplaceTo.length(), Replace);

		pos = S.find(ReplaceTo);

	}

	return S;



}
static string IsPucuchinToRemove(string S) {
	string word = "";
	for (int i = 0; i < S.size(); i++) {

		if (!ispunct(S[i])) {
			word += S[i];

		}

	}


	return word;


}
void IsPucuchinToRemove() {

	_Value = IsPucuchinToRemove(_Value);
}
};


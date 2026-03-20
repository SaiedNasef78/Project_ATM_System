#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <ctime>
#include "clsString.h"

//#include "clsPeriode.h"
using namespace std;

	class clsDate
	{
	private:
		string _Date;
		short _Day;
		short _Month;
		short _Year;
	public:
		clsDate() {
			time_t now = time(0);
			tm* t = localtime(&now);
			_Year = (short)(1900 + t->tm_year);
			_Month = (short)(t->tm_mon + 1);
			_Day = (short)(t->tm_mday);
		}
		clsDate(string Date) {

			clsString cstring;
			vector<string>dates = cstring.Splite(Date, "/");


			_Day = (short)stoi(dates.at(0));
			_Month = (short)stoi(dates.at(1));
			_Year = (short)stoi(dates.at(2));


		}
		static	bool IsLeepYear(short Year) {

			return ((Year % 100 != 0 && Year % 4 == 0) || (Year % 400 == 0));




		}
		bool  IsLeepYear() {
			return  IsLeepYear(_Year);
		}
		static short  NumberOfDaysInAMonth(int N, int Year) {
			if (N < 1 || N > 12) {
				return 0;
			}
			short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
			return (N == 2) ? (IsLeepYear(Year) ? 29 : 28) : NumberOfDays[N - 1];
		}
		clsDate(int Day, int Month, int Year) {
			_Day = Day;
			_Month = Month;
			_Year = Year;

		}
		static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
		{
			clsDate Date;
			short RemainingDays = DateOrderInYear;
			short MonthDays = 0;

			Date._Year = Year;
			Date._Month = 1;

			while (true)
			{
				MonthDays = NumberOfDaysInAMonth(Date._Month, Year);

				if (RemainingDays > MonthDays)
				{
					RemainingDays -= MonthDays;
					Date._Month++;
				}
				else
				{
					Date._Day = RemainingDays;
					break;
				}
			}

			return Date;
		}

		clsDate(short DateOrderInYear, short Year)
		{
			//This will construct a date by date order in year
			clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);
			_Day = Date1._Day;
			_Month = Date1._Month;
			_Year = Date1._Year;

		}
		static clsDate GetSystemDate() {


			time_t t = time(0);
			tm* now = localtime(&t);
			short Year = now->tm_year + 1900;
			short Month = now->tm_mon + 1;
			short Day = now->tm_mday;
			return clsDate(Day, Month, Year);
		}
		void setDay(short day) {
			_Day = day;
		}
		short Day() {
			return _Day;
		}
		__declspec(property(get = Day, put = setDay)) short day;
		void setMonth(short Month) {
			_Month = Month;
		}
		short Month() {
			return _Month;
		}
		__declspec(property(get = Month, put = setMonth)) short month;
		void setYear(short Year) {
			_Year = Year;
		}
		short Year() {
			return _Year;
		}
		__declspec(property(get = Year, put = setYear)) short year;
		static string DateToString(clsDate Date) {
			return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
		}
		void DateToString() {
			cout << DateToString(*this) << endl;
		}
		static int NumberOfDaysinYear(short Year) {
			return IsLeepYear(Year) ? 366 : 365;
		}
		int  NumberOfDaysinYear() {
			return  NumberOfDaysinYear(_Year);
		}
		static int NumberOfHours(short Year) {

			return NumberOfDaysinYear(Year) * 24;

		}
		int  NumberOfHours() {
			return  NumberOfHours(_Year);
		}
		static int NumberOfMinutes(short Year) {

			return NumberOfHours(Year) * 60;

		}
		int NumberOfMinutes() {
			return  NumberOfMinutes(_Year);
		}
		static int NumberOfSeconds(short Year) {

			return NumberOfMinutes(Year) * 60;
		}
		int NumberOfSeconds() {
			return NumberOfSeconds(_Year);
		}
		static string DayShortName(short DayOfWeekOrder) {
			string ArrDayName[] = { "Sun","Mon","Tuse","Wedns","Thurs","Fri","Satur" };
			return ArrDayName[DayOfWeekOrder];
		}
		static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
			short TotalDays = 0;
			for (short i = 1; i < Month; i++) {

				TotalDays += NumberOfDaysInAMonth(i, Year);
			}
			TotalDays += Day;
			return TotalDays;
		}
		void NumberOfDaysFromTheBeginingOfTheYear() {
			cout << NumberOfDaysFromTheBeginingOfTheYear(_Day, _Month, _Year) << endl;
		}
		bool CheakDateLess(clsDate Date1, clsDate Date2) {

			return ((Date1._Day > Date2._Day) || (Date1._Month > Date2._Month) || (Date1._Year > Date2._Year));


		}
		static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {

			return (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ?
				(Date1._Month < Date2._Month) ? true : (Date1._Month == Date2._Month) ? (Date1._Day < Date2._Day) : false : false);

		}
		void IsDate1BeforeDate2(clsDate Date2) {
			if (IsDate1BeforeDate2(*this, Date2))
				cout << "No, Date1 Smaller than Date2";
			else cout << "yes ,Date1 Larger Date2" << endl;
		}
		static clsDate AddDyasToDate(short TotalDays, clsDate Date) {
			short Days = NumberOfDaysFromTheBeginingOfTheYear(Date._Day, Date._Month, Date._Year);
			short Remining = Days + TotalDays;
			Date._Month = 1;
			Date._Day += TotalDays;
			short MonthDays;
			while (true)
			{

				MonthDays = NumberOfDaysInAMonth(Date._Month, Date._Year);
				/* if (Date.Day > MonthDays) {

					 Date.Day -= MonthDays;
					 Date.Month++;
					 if (Date.Month > 12) {
						 Date.Month = 1;
						 Date.Year++;

					 }

				 }
				 else {
					 break;
				 }*/
				if (Remining > MonthDays) {
					Remining -= MonthDays;
					Date._Month++;



					if (Date._Month > 12)
					{

						Date._Month = 1;
						Date._Year++;
					}

				}
				else {
					Date._Day = Remining;
					break;

				}
			}



			return Date;
		}
		static 	bool IsLastDayInMonth(clsDate& Date) {

			return (Date._Day == NumberOfDaysInAMonth(Date._Month, Date._Year));

		}
		static bool IsLastMonthInYear(clsDate& Date) {

			return (Date._Month == 12);

		}

		static clsDate AddOneDay(clsDate Date) {
			if (IsLastDayInMonth(Date)) {
				Date._Day = 1;


				if (IsLastMonthInYear(Date)) {

					Date._Month = 1;
					Date._Year++;


				}
				else {
					Date._Month++;

				}

			}
			else {
				Date._Day++;
			}
			return Date;
		}
		void AddOneDay() {
			*this=AddOneDay(*this);
		}
		static   void SwaapDate(clsDate& Date1, clsDate& Date2) {
			clsDate TempDate;
			TempDate._Day = Date1._Day;
			TempDate._Month = Date1._Month;
			TempDate._Year = Date1._Year;

			Date1._Day = Date2._Day;
			Date1._Month = Date2._Month;
			Date1._Year = Date2._Year;

			Date2._Day = TempDate._Day;
			Date2._Month = TempDate._Month;
			Date2._Year = TempDate._Year;



		}
		void SwaapDate(clsDate& Date2) {
			SwaapDate(*this, Date2);


		}
		static int GetDifferenceInDays(clsDate Datel, clsDate Date2, bool IncludeEndDay =false)

		{

			//this will take care of negative diff

			int Days = 0;

			short SawpFlagValue = 1;

			if (!IsDate1BeforeDate2(Datel, Date2))
			{


				//Swap Dates

				SwaapDate(Datel, Date2);

				SawpFlagValue = -1;
			}
		while (IsDate1BeforeDate2(Datel, Date2)) {

			Days++;

			Datel=Datel.AddOneDay(Datel);

		}

		return IncludeEndDay ? ++Days *SawpFlagValue : Days*SawpFlagValue; 
}
			
			int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay =false)

			{
				return GetDifferenceInDays(*this, Date2, IncludeEndDay);
			}

			
		static string MonthName(short Month) {
			string Arr[] = { "Jan","Feb","Mar","Ap","May","Jun","Jul","Aug","Sep","Oct","Nov","Dece" };

			return Arr[Month - 1];
		}

		static short DayOrder(short Day, short Month, short Year) {
			short a = (14 - Month) / 12;
			short y = Year - a;
			short m = Month + 12 * a - 2;
			short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
			return d;
		}

		static void PrintNumberOfDays(short Year, short Month) {
			short NumberOfDays = NumberOfDaysInAMonth(Month, Year);
			short current = DayOrder(1, Month, Year);
			printf("\n\n__________________________%s_______________________\n", MonthName(Month).c_str());

			printf("  Sun  Mon  Tus  Wed  Thu  Fri  Sat\n");
			int i;
			for (i = 0; i < current; i++)
				printf("     ");

			for (short j = 1; j <= NumberOfDays; j++) {
				printf("%5d", j);

				if (
					++i == 7) {
					i = 0;
					printf("\n");

				}

			}

		}
		static void PrintAllDaysYear(short Year) {

			printf("\n\n_____________________________________\n\n");
			printf("\t\t Calender= %d", Year);
			printf("\n\n_____________________________________\n");
			for (short m = 1; m <= 12; m++) {
				PrintNumberOfDays(Year, m);

			}

		}
		void PrintAllDaysYear() {
			PrintAllDaysYear(_Year);
		}
		void PrintNumberOfDays(clsDate Date) {

			Date.PrintNumberOfDays(Date._Year, Date._Month);
		}
		static	clsDate IncreaseDateByOneWeek(clsDate& Date) {
			for (short i = 1; i <= 7; i++) {

				Date = AddOneDay(Date);
			}

			return Date;
		}
		void  IncreaseDateByOneWeek() {

			IncreaseDateByOneWeek(*this);

		}
		static clsDate IncreaseDateBy_X_Weeks(short NumberInWeek, clsDate& Date) {
			for (short i = 1; i <= NumberInWeek; i++) {
				Date = IncreaseDateByOneWeek(Date);

			}
			return Date;
		}
		void IncreaseDateBy_X_Weeks(short NumberInWeek) {

			IncreaseDateBy_X_Weeks(NumberInWeek, *this);

		}
		static clsDate IncreaseDateByOneMonth(clsDate& Date) {
			if (Date._Month == 12) {
				Date._Month = 1;
				Date._Year++;
			}
			else {
				Date._Month++;
			}
			short NumberInMonth = NumberOfDaysInAMonth(Date._Month, Date._Year);
			if (Date._Day > NumberInMonth) {
				Date._Day = NumberInMonth;

			}
			return Date;

		}
		void IncreaseDateByOneMonth() {
			IncreaseDateByOneMonth(*this);
		}
		static	clsDate IncreaseDateBy_X_Month(short NumberInMonth, clsDate& Date) {
			for (short i = 1; i <= NumberInMonth; i++) {
				Date = IncreaseDateByOneMonth(Date);
			}
			return Date;

		}
		void  IncreaseDateBy_X_Month(short NumberInMonth) {
			IncreaseDateBy_X_Month(NumberInMonth, *this);

		}
		static clsDate IncreaseDateByOneYear(clsDate& Date) {
			Date._Year++;
			return Date;
		}
		void  IncreaseDateByOneYear() {

			IncreaseDateByOneYear(*this);
		}
		static clsDate IncreaseDateBy_X_Year(short Years, clsDate& Date) {
			for (short i = 1; i <= Years; i++) {
				Date = IncreaseDateByOneYear(Date);

			}
			return Date;
		}
		void IncreaseDateBy_X_Year(short Years) {
			IncreaseDateBy_X_Year(Years, *this);


		}
		static clsDate IncreaseDateBy_X_YearFaster(short Years, clsDate& Date) {
			Date._Year += Years;
			return Date;
		}
		static clsDate IncreaseDateByOneDeced(clsDate& Date) {
			/* for (short i = 1; i <= 10; i++) {
				 Date=IncreaseDateBy_X_YearFaster(1,Date);
			 }*/
			Date._Year += 10;
			return Date;
		}
		void IncreaseDateByOneDeced() {
			IncreaseDateByOneDeced(*this);
		}
		static clsDate IncreasDateBy_X_Deced(short Decades, clsDate& Date) {

			for (short i = 1; i <= Decades * 10; i++) {

				Date = IncreaseDateByOneYear(Date);
			}

			return Date;


		}
		void IncreasDateBy_X_Deced(short Decades) {

			IncreasDateBy_X_Deced(Decades, *this);
		}
		static clsDate IncreaseDateBy_X_DecadFaster(short Decads, clsDate& Date) {
			Date._Year += Decads * 10;
			return Date;
		}
		void  IncreaseDateBy_X_DecadFaster(short Decades) {

			IncreaseDateBy_X_DecadFaster(Decades, *this);
		}
		static clsDate IncreaseDateByOneCentury(clsDate& Date) {

			Date._Year += 100;
			return Date;
		}
		void IncreaseDateByOneCentury() {

			IncreaseDateByOneCentury(*this);
		}
		static clsDate InCreaseDateByOneMillennium(clsDate& Date) {
			Date._Year += 1000;
			return Date;

		}
		void InCreaseDateByOneMillennium() {
			InCreaseDateByOneMillennium(*this);
		}
		static clsDate DecreaseDateByOneDays(clsDate& Date) {

			// short MonthDyas = MyLeap::NumberOfMonthInDay(Date.Month, Date.Year);

			if (Date._Day == 1) {
				if (Date._Month == 1) {
					Date._Month = 12;
					Date._Year--;
					Date._Day = NumberOfDaysInAMonth(Date._Month, Date._Year);

				}
				else {
					Date._Month--;
					Date._Day = NumberOfDaysInAMonth(Date._Month, Date._Year);
				}

			}
			else {
				Date._Day--;
			}



			return Date;





		}
		void DecreaseDateByOneDays() {
			DecreaseDateByOneDays(*this);
		}
		static clsDate DecreaseDateBy_X_Days(short Days, clsDate& Date) {
			for (short i = 1; i <= Days; i++) {
				Date = DecreaseDateByOneDays(Date);

			}
			return Date;


		}
		void DecreaseDateBy_X_Days(short Days) {

			DecreaseDateBy_X_Days(Days, *this);
		}
		static 	clsDate DecreaseDateByOneWeek(clsDate& Date) {

			Date = DecreaseDateBy_X_Days(7, Date);
			return Date;


		}
		void DecreaseDateByOneWeek() {
			DecreaseDateByOneWeek(*this);
		}
		static 	clsDate DecreaseDateBy_X_Weeks(short weeks, clsDate Date) {
			for (short i = 1; i <= weeks; i++) {

				Date = DecreaseDateByOneWeek(Date);
			}

			return Date;
		}
		void DecreaseDateBy_X_Weeks(short weeks) {

			DecreaseDateBy_X_Weeks(weeks, *this);

		}
		static clsDate DecreaseDateByOneMonth(clsDate& Date) {
			// short MonthDays=MyLeap::NumberOfMonthInDay(Date.Month,Date.Year);
			if (Date._Month == 1) {

				Date._Month = 12;
				Date._Year--;


			}
			else {
				Date._Month--;
			}
			short MonthDays = NumberOfDaysInAMonth(Date._Month, Date._Year);
			if (Date._Day > MonthDays) {
				Date._Day = MonthDays;

			}

			return Date;


		}

		void DecreaseDateByOneMonth() {

			DecreaseDateByOneMonth(*this);
		}
		static clsDate DecreaseDateBy_X_Months(short months, clsDate& Date) {

			for (short i = 1; i <= months; i++) {

				Date = DecreaseDateByOneMonth(Date);
			}
			return Date;

		}
		void DecreaseDateBy_X_Months(short months) {

			DecreaseDateBy_X_Months(months, *this);
		}
		static clsDate DecreaseDateByOneYear(clsDate& Date) {

			Date._Year--;
			return Date;
		}
		void  DecreaseDateByOneYear() {
			DecreaseDateByOneYear(*this);
		}
		static clsDate DecreaseDateBy_X_Years(short years, clsDate& Date) {

			for (short i = 1; i <= years; i++) {
				Date = DecreaseDateByOneYear(Date);

			}
			return Date;



		}
		void  DecreaseDateBy_X_Years(short years) {
			DecreaseDateBy_X_Years(years, *this);
		}
		static clsDate  DecreaseDateBy_X_YearsFaster(short years, clsDate& Date) {

			Date._Year -= years;
			return Date;
		}
		void DecreaseDateBy_X_YearsFaster(short years) {
			DecreaseDateBy_X_YearsFaster(years, *this);
		}
		static clsDate DecreaseDateByOneDecad(clsDate& Date) {


			Date._Year -= 10;
			return Date;

		}
		void  DecreaseDateByOneDecad() {
			DecreaseDateByOneDecad(*this);
		}
		static clsDate DecreaseDateBy_X_Decad(short Decads, clsDate& Date) {
			for (short i = 1; i <= Decads; i++) {

				Date = DecreaseDateByOneDecad(Date);
			}

			return Date;
		}
		void DecreaseDateBy_X_Decad(short Decads) {
			DecreaseDateBy_X_Decad(Decads, *this);
		}
		static clsDate DecreaseDateBy_X_DecadFaster(short Decads, clsDate& Date) {
			Date._Year -= Decads * 10;
			return Date;
		}
		void DecreaseDateBy_X_DecadFaster(short Decads) {
			DecreaseDateBy_X_DecadFaster(Decads, *this);
		}
		static clsDate DecreaseDateByOneCentury(clsDate& Date)
		{

			Date._Year -= 100;

			return Date;
		}
		void DecreaseDateByOneCentury() {
			DecreaseDateByOneCentury(*this);
		}
		static clsDate DecreaseDateByOneMillennium(clsDate& Date) {
			Date._Year -= 1000;
			return Date;
		}
		void  DecreaseDateByOneMillennium() {
			DecreaseDateByOneMillennium(*this);
		}
		static	short DayOrder(clsDate& Date) {


			return DayOrder(Date._Day, Date._Month, Date._Year);

		}

		static bool IsEndOfWeek(clsDate Date) {

			return (DayOrder(Date) == 6);

		}
		void IsEndOfWeek() {
			cout << "Is it End of Week?\n";
			if (IsEndOfWeek(*this))
			{
				cout << "Yes End Of Week";
			}
			else {
				cout << "No Not end Of Week";
			}
		}
		static	bool IsWeekend(clsDate Date) {

			return (DayOrder(Date) == 5 || DayOrder(Date) == 6);

		}
		void IsWeekend() {

			cout << "\n\nIs it Week End ?\n";
			if (IsWeekend(*this)) {
				cout << "Yes it is a week end";


			}
			else {
				cout << "No not a week end";
			}

		}

		static bool IsBusinessDay(clsDate Date) {
			/*short Index = DayOrder(Date);
			return (Index >= 5 && Index <= 4);*/

			return (!IsWeekend(Date));
		}
		static string NameDay(short DaysIndex) {
			string Arr[] = { "Sun","Mon","Tuse","Wed","Thur","Fri","Satu" };
			return Arr[DaysIndex];


		}
		void  IsBusinessDay() {
			cout << "\n\nIs it Business Day?\n";
			if (IsBusinessDay(*this)) {
				cout << "Yes it is a business day.";



			}
			else {
				cout << "No it is Not a business day.(" << NameDay(DayOrder(*this)) << ")";
			}
		}
		static short DayUntilTheEndOfWeek(clsDate Date) {

			return 6 - DayOrder(Date);

		}
		void  DayUntilTheEndOfWeek() {
			cout << "\n\nDays until end of week: " << DayUntilTheEndOfWeek(*this) << " Days(s)\n";
		}
		static short DayUntilTheEndOfMonth(clsDate Date) {
			clsDate Stdate;
			Stdate._Day = NumberOfDaysInAMonth(Date._Month, Date._Year);
			Stdate._Month = Date._Month;
			Stdate._Year = Date._Year;
			/*short MonthDays = MyLeap::NumberOfMonthInDay(Date.Month, Date.Year);
			short Remining = MonthDays - Date.Day;
			return Remining;*/
			return 	GetDifferenceInDays(Date, Stdate, true);
		}
		void DayUntilTheEndOfMonth() {

			cout << "Days until end of month: " << DayUntilTheEndOfMonth(*this) << " Days (s)\n";
		}
		short DayUntilTheEndOfyear(clsDate Date1) {
			/*short MonthDays;
			short totaldays = 0;
			while (true) {
				Date.Month++;
				if (Date.Month == 1) {

					break;
				}
				MonthDays = MyLeap::NumberOfMonthInDay(Date.Month, Date.Year);

				totaldays += MonthDays;


			}

			totaldays += Reminingdays;
			return totaldays;*/

			clsDate Date2;
			Date2._Day = 31;
			Date2._Month = 12;
			Date2._Year = Date1._Year;

			return GetDifferenceInDays(Date1, Date2, true);
		}
		void DayUntilTheEndOfyear() {
			cout << "Dayse until end of month: " << DayUntilTheEndOfyear(*this);
		}
		static 	clsDate CalculateVactionDays(short VactionDays, clsDate& Date) {
			short WeekEndCounter = 0;
			while (IsWeekend(Date)) {

				Date = AddOneDay(Date);
			}
			for (short i = 1; i <= VactionDays + WeekEndCounter; i++) {

				if (IsWeekend(Date))
					WeekEndCounter++;
				Date = AddOneDay(Date);



			}
			/* while (MyWeek::IsWeekend(Date)) {
				 Date = MyDate::IncreseDateByOneDay(Date);

			 }*/

			return Date;
		}
		void CalculateVactionDays(short VactionDays) {
			CalculateVactionDays(VactionDays, *this);
		}
		static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {
			return (Date1._Year == Date2._Year) ? (Date1._Month == Date2._Month) ? (Date1._Day == Date2._Day) ? true : false : false : false;
			/*return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);*/

		}
		bool IsDate1EqualDate2(clsDate Date2) {
			return IsDate1EqualDate2(*this, Date2);
		}
		static 	bool IsDate1AfterDat2(clsDate Date1, clsDate Date2) {

			return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
		}
		bool IsDate1AfterDat2(clsDate Date2) {
			return IsDate1AfterDat2(*this, Date2);
		}
		enum enDaste1AndDate2 {
			Before = -1,
			Equal = 0,
			After = 1

		};

		static enDaste1AndDate2 CompareDates(clsDate Date1, clsDate Date2) {
			if (IsDate1BeforeDate2(Date1, Date2))
				return enDaste1AndDate2::Before;

			if (IsDate1EqualDate2(Date1, Date2))
				return enDaste1AndDate2::Equal;


			return enDaste1AndDate2::After;
		}
		enDaste1AndDate2 CompareDates(clsDate Date1) {
			return  CompareDates(*this, Date1);
		}
		

		static bool IsValidateDate(clsDate Date) {
			if (Date.month > 12 || Date.month <= 0)
				return 0;
			if (Date.day > 31 || Date.day < 1)
				return false;
			if (Date.month == 2) {

				if (clsDate::IsLeepYear(Date.year))
				{
					if (Date.day > 29)
						return false;
				}
				else {
					if (Date.day > 28)
						return false;
				}

			}
			short MonthDays = clsDate::NumberOfDaysInAMonth(Date.month, Date.year);
			if (Date.day > MonthDays  ) {
				return false;
			}


			return true;


		}

		/*void IsValidDate() {
			if (IsValidateDate(*this)) {
				cout << "\n\nYes, Is a validate Date";
			}
			else {

				cout << "\n\nNo, Is a Not validate Date";

			}
		}*/
		static bool IsValideDate(clsDate Date)
		{
			return	clsDate::IsValidateDate(Date);
		}
		void Print() {
			DateToString();

		}
		

		
		 clsDate StringToDate(string Dat) {

		clsDate Date;
			vector <string> V = clsString::Splite(Dat, "/");;
			Date._Day = stoi(V[0]);
			Date._Month = stoi(V[1]);
			Date._Year = stoi(V[2]);
			return Date;
		}
		
		static string Replace(string &S1, string ReplaceTo, string ToReplace) {

			short pos = S1.find(ReplaceTo);
			while (pos != std::string::npos) {
				S1 = S1.replace(pos, ReplaceTo.length(), ToReplace);


				pos = S1.find(ReplaceTo);

			}


			return S1;

		}
		


	static 	string   PrintFormatDate(clsDate Date, string Formating = "dd/mm/yyyy") {
			string FormatedString = "";
			FormatedString = Formating;
			FormatedString = Replace(Formating, "dd", to_string(Date._Day));
			FormatedString = Replace(FormatedString, "mm", to_string(Date._Month));
			FormatedString = Replace(FormatedString, "yyyy", to_string(Date._Year));

			return FormatedString;

		}
	string   PrintFormatDate(string Formating = "dd/mm/yyyy") {

		return PrintFormatDate(*this, Formating );
	}
		

};

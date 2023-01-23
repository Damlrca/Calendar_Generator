#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <locale>
#include <codecvt>
using namespace std;

const wstring months_names[]
{ L"January",L"February",
L"March",L"April",L"May",
L"June",L"July",L"August",
L"September",L"October",L"November",
L"December" };

const wstring months_names_ru[]
{ L"Январь",L"Февраль",
L"Март",L"Апрель",L"Май",
L"Июнь",L"Июль",L"Август",
L"Сентябрь",L"Октябрь",L"Ноябрь",
L"Декабрь" };

const wstring day_of_week[]
{
	L"MO",L"TU",L"WE",L"TH",L"FR",L"SA",L"SU"
};

const wstring day_of_week_ru[]
{
	L"ПН",L"ВТ",L"СР",L"ЧТ",L"ПТ",L"СБ",L"ВС"
};

const int month_length[2][12]{
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

const wstring big_digit[10][5]{
	{L"███",
	 L"█ █",
	 L"█ █",
	 L"█ █",
	 L"███"},

	{L" █ ",
	 L"██ ",
	 L" █ ",
	 L" █ ",
	 L"███"},
	 
	{L"███",
	 L"  █",
	 L"███",
	 L"█  ",
	 L"███"},
	 
	{L"███",
	 L"  █",
	 L"███",
	 L"  █",
	 L"███"},
	 
	{L"█ █",
	 L"█ █",
	 L"███",
	 L"  █",
	 L"  █"},
	 
	{L"███",
	 L"█  ",
	 L"███",
	 L"  █",
	 L"███"},
	 
	{L"███",
	 L"█  ",
	 L"███",
	 L"█ █",
	 L"███"},
	 
	{L"███",
	 L"  █",
	 L"  █",
	 L"  █",
	 L"  █"},
	 
	{L"███",
	 L"█ █",
	 L"███",
	 L"█ █",
	 L"███"},
	 
	{L"███",
	 L"█ █",
	 L"███",
	 L"  █",
	 L"███"}
};

inline constexpr int is_leap(const int x) {
	return (x % 4 == 0 && x % 100 != 0) || x % 400 == 0;
}

int main() {

	int this_year;
	cout << "Input year: ";
	cin >> this_year;
	if (this_year < 1970 || this_year > 3000) {
		cout << "expected 1970 - 3000";
		return 0;
	}
	
	string year_string = to_string(this_year);
	string filename = "calendar_" + year_string + ".txt";

	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());
	wofstream fout(filename);
	fout.imbue(utf8_locale);

	for (int i = 0; i < 5; i++) {
		for (char c : year_string) {
			fout << big_digit[c - '0'][i] << L" ";
		}
		fout << L"\n";
	}
	fout << L"\n";

	int day_now = 3;
	for (int year = 1970; year < this_year; year++)
		day_now = (day_now + 365 + is_leap(year)) % 7;
	const int this_year_is_leap = is_leap(this_year);
	for (int month = 0; month < 12; month++) {
		fout << months_names_ru[month] << L"\n";
		for (int i = 0; i < 7; i++)
			fout << L" " << day_of_week_ru[i];
		fout << L"\n";
		int t = 1;
		for (int i = 0; i < 3 * day_now; i++) fout << " ";
		for (int i = 0; i < month_length[this_year_is_leap][month]; i++) {
			fout << setw(3) << t;
			t++;
			day_now++;
			day_now %= 7;
			if (day_now == 0) fout << L"\n";
		}
		fout << L"\n";
	}

	fout.close();

	cout << "calendar saved in file " << filename << "\n";

	return 0;
}
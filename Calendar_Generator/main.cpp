#include "calendar_constants.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <locale>
#include <codecvt>
using namespace std;

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
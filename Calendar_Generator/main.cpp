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

wstring fit_to_3(wstring x) {
	while (x.size() < 3)
		x = L" " + x;
	return x;
}

void generate_calendar(int year, string filename, const wstring* months_names, const wstring* day_of_week) {
	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());
	wofstream fout(filename);
	fout.imbue(utf8_locale);

	int height = 4;
	int width = 12 / height;

	for (int i = 0; i < 5; i++) {
		for (int i = 0; i < 3 * 7 + 7; i++)
			fout << L" ";
		for (char c : to_string(year)) {
			fout << big_digit[c - '0'][i] << L" ";
		}
		fout << L"\n";
	}

	int day_now = 3;
	for (int i = 1970; i < year; i++)
		day_now = (day_now + 365 + is_leap(i)) % 7;
	const int this_year_is_leap = is_leap(year);

	for (int row = 0; row < height; row++) {
		wstring buffer[8];

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < 7; j++)
				buffer[1] += L" " + day_of_week[j];
			if (i + 1 < width)
				buffer[1] += L"   ";
		}

		for (int month = row * width; month < (row + 1) * width; month++) {
			buffer[0] += months_names[month];
			if (month + 1 < (row + 1) * width)
				buffer[0] += L"   ";

			int line_now = 0;
			int day = 1;
			int symbols_added = 0;

			for (int i = 0; i < 3 * day_now; i++) {
				buffer[line_now + 2] += L" ";
				symbols_added++;
			}

			while (line_now < 6) {
				while (day <= month_length[this_year_is_leap][month]) {
					buffer[line_now + 2] += fit_to_3(to_wstring(day));
					day++;
					day_now++;
					symbols_added += 3;
					day_now %= 7;
					if (day_now == 0)
						break;
				}
				while (symbols_added < 3 * 7) {
					buffer[line_now + 2] += L" ";
					symbols_added++;
				}
				if (month + 1 < (row + 1) * width)
					buffer[line_now + 2] += L"   ";
				line_now++;
				symbols_added = 0;
			}

		}

		for (int i = 0; i < 3 * 7 * width + 3 * (width - 1); i++)
			fout << L" ";
		fout << L"\n";
		for (auto& o : buffer)
			fout << o << L"\n";
	}

	fout.close();
}

int main() {
	int this_year;
	cout << "Input year (1970-3000): ";
	cin >> this_year;
	if (this_year < 1970 || this_year > 3000) {
		cout << "expected 1970 - 3000";
		return 0;
	}
	
	string lang;
	cout << "Language (eng/rus): ";
	cin >> lang;
	if (lang != "eng" && lang != "rus") {
		cout << "expected \"eng\" or \"rus\"\n";
		return 0;
	}

	string year_string = to_string(this_year);
	string filename = "calendar_" + year_string;

	if (lang == "eng") {
		filename += "_eng.txt";
		generate_calendar(this_year, filename, months_names, day_of_week);
	}
	else if (lang == "rus") {
		filename += "_rus.txt";
		generate_calendar(this_year, filename, months_names_ru, day_of_week_ru);
	}
	else {
		cout << "expected \"eng\" or \"rus\"\n";
		return 0;
	}

	cout << "calendar saved in file " << filename << "\n";

	return 0;
}
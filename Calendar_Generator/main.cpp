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

wstring fit_to_center(wstring x, size_t width) {
	size_t need = max(size_t(0), width - x.size());
	size_t right = need / 2;
	size_t left = need - right;
	return wstring(left, L' ') + x + wstring(right, L' ');
}

wstring fit_to_right(wstring x, size_t width) {
	return wstring(max(size_t(0), width - x.size()), L' ') + x;
}

void generate_calendar(const int year, string filename, const wstring* months_names, const wstring* day_of_week, const int height) {
	const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());
	wofstream fout(filename);
	fout.imbue(utf8_locale);

	const int width = 12 / height;

	const int width_in_symbols = 3 * 7 * width + 3 * (width - 1);

	for (int i = 0; i < 5; i++) {
		wstring t;
		for (char c : to_string(year))
			t += big_digit[c - '0'][i] + L" ";
		fout << fit_to_center(t, width_in_symbols) << L"\n";
	}

	int day_now = 3;
	for (int i = 1970; i < year; i++)
		day_now = (day_now + 365 + is_leap(i)) % 7;
	const int this_year_is_leap = is_leap(year);

	for (int row = 0; row < height; row++) {
		wstring buffer[8];

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < 7; j++)
				buffer[1] += fit_to_right(day_of_week[j], 3);
			if (i + 1 < width)
				buffer[1] += L"   ";
		}

		for (int month = row * width; month < (row + 1) * width; month++) {
			buffer[0] += L' ' + fit_to_center(months_names[month], 20);
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
					buffer[line_now + 2] += fit_to_right(to_wstring(day), 3);
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

		fout << wstring(width_in_symbols, L' ');

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
		cout << "Error: expected 1970 - 3000" << endl;
		return -1;
	}
	
	string lang;
	cout << "Language (eng/rus): ";
	cin >> lang;
	if (lang != "eng" && lang != "rus") {
		cout << "Error: expected \"eng\" or \"rus\"" << endl;
		return -1;
	}

	int height;
	cout << "Input number of rows (1/2/3/4/6/12): ";
	cin >> height;
	if (height <= 0 || 12 % height != 0) {
		cout << "Error: expected another number of rows" << endl;
		return -1;
	}

	string year_string = to_string(this_year);
	string filename = "c_" + year_string;

	if (lang == "eng") {
		filename += "_" + lang + "_" + to_string(height) + "x" + to_string(12 / height) + ".txt";
		generate_calendar(this_year, filename, months_names, day_of_week, height);
	}
	else if (lang == "rus") {
		filename += "_" + lang + "_" + to_string(height) + "x" + to_string(12 / height) + ".txt";
		generate_calendar(this_year, filename, months_names_ru, day_of_week_ru, height);
	}
	else {
		cout << "expected \"eng\" or \"rus\"" << endl;
		return -1;
	}

	cout << "calendar saved in file " << filename << endl;

	return 0;
}

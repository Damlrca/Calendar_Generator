#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const string months_names[]
{ "January","February",
"March","April","May",
"June","July","August",
"September","October","November",
"December" };

const string day_of_week[]
{
	"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"
};

const int month_length[2][12]{
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
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
	int day_now = 3;
	for (int year = 1970; year < this_year; year++)
		day_now = (day_now + 365 + is_leap(year)) % 7;
	const int this_year_is_leap = is_leap(this_year);
	cout << this_year << "\n";
	for (int month = 0; month < 12; month++) {
		cout << months_names[month] << "\n";
		int t = 1;
		for (int i = 0; i < 3 * day_now; i++) cout << " ";
		for (int i = 0; i < month_length[this_year_is_leap][month]; i++) {
			cout << setw(3) << t;
			t++;
			day_now++;
			day_now %= 7;
			if (day_now == 0) cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}
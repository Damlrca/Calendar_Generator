#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const string months_names[]
{ "January","February",
"March","April","May",
"June","July","August",
"September","October","November",
"December" };

const string months_names_ru[]
{ "Январь","Февраль",
"Март","Апрель","Май",
"Июнь","Июль","Август",
"Сентябрь","Октябрь","Ноябрь",
"Декабрь" };

const string day_of_week[]
{
	"MO","TU","WE","TH","FR","SA","SU"
};

const string day_of_week_ru[]
{
	"ПН","ВТ","СР","ЧТ","ПТ","СБ","ВС"
};

const int month_length[2][12]{
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

const string big_digit[10][5]{
	{"###",
	 "# #",
	 "# #",
	 "# #",
	 "###"},

	{" # ",
	 "## ",
	 " # ",
	 " # ",
	 "###"},

	{"###",
	 "  #",
	 "###",
	 "#  ",
	 "###"},

	{"###",
	 "  #",
	 "###",
	 "  #",
	 "###"},

	{"# #",
	 "# #",
	 "###",
	 "  #",
	 "  #"},

	{"###",
	 "#  ",
	 "###",
	 "  #",
	 "###"},

	{"###",
	 "#  ",
	 "###",
	 "# #",
	 "###"},

	{"###",
	 "  #",
	 "  #",
	 "  #",
	 "  #"},

	{"###",
	 "# #",
	 "###",
	 "# #",
	 "###"},

	{"###",
	 "# #",
	 "###",
	 "  #",
	 "###"}
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
	ofstream fout(filename);

	for (int i = 0; i < 5; i++) {
		for (char c : year_string) {
			fout << big_digit[c - '0'][i] << " ";
		}
		fout << "\n";
	}
	fout << "\n";

	int day_now = 3;
	for (int year = 1970; year < this_year; year++)
		day_now = (day_now + 365 + is_leap(year)) % 7;
	const int this_year_is_leap = is_leap(this_year);
	for (int month = 0; month < 12; month++) {
		fout << months_names_ru[month] << "\n";
		for (int i = 0; i < 7; i++)
			fout << " " << day_of_week_ru[i];
		fout << "\n";
		int t = 1;
		for (int i = 0; i < 3 * day_now; i++) fout << " ";
		for (int i = 0; i < month_length[this_year_is_leap][month]; i++) {
			fout << setw(3) << t;
			t++;
			day_now++;
			day_now %= 7;
			if (day_now == 0) fout << "\n";
		}
		fout << "\n";
	}

	fout.close();

	cout << "calendar saved in file " << filename << "\n";

	return 0;
}
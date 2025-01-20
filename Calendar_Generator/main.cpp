#include "calendar_constants.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <locale>
#include <codecvt>
#include "generator.h"

using namespace std;

void write_calendar(string filename, int year, int H, LANG lang, const title_number_font& t_font) {
    auto calendar = generate_calendar(year, H, lang, t_font).get_block();

    const locale utf8_locale = locale(locale(), new codecvt_utf8<wchar_t>());
    wofstream fout(filename);
    fout.imbue(utf8_locale);

    for (auto& line : calendar) {
        fout << line << L"\n";
    }

    fout.close();
}

int main() {
    int year;
    cout << "Input year (1970-3000): ";
    cin >> year;
    if (year < 1970 || year > 3000) {
        cout << "Error: expected 1970 - 3000" << endl;
        return -1;
    }
    
    string lang_str;
    cout << "Language (eng/rus): ";
    cin >> lang_str;
    if (lang_str != "eng" && lang_str != "rus") {
        cout << "Error: expected \"eng\" or \"rus\"" << endl;
        return -1;
    }
    LANG lang;
    if (lang_str == "eng") {
        lang = LANG::ENG;
    }
    else {
        lang = LANG::RUS;
    }

    int H;
    cout << "Input number of rows (1/2/3/4/6/12): ";
    cin >> H;
    if (H <= 0 || 12 % H != 0) {
        cout << "Error: expected another number of rows" << endl;
        return -1;
    }

    string year_string = to_string(year);
    string filename = "c_" + year_string;
    filename += "_" + lang_str + "_" + to_string(H) + "x" + to_string(12 / H) + ".txt";

    title_number_font t_font(big_digit, 1, HOR_ALIGH::DOWN);
    write_calendar(filename, year, H, lang, t_font);

    cout << "calendar saved in file " << filename << endl;

    return 0;
}

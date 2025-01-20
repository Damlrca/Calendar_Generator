#include "generator.h"

bool is_leap(int x) {
    return (x % 4 == 0 && x % 100 != 0) || x % 400 == 0;
}

wstring_block generate_month(int year, int month, LANG lang) {
    wstring_block title(0, 0);
    switch (lang) {
    case LANG::ENG:
    {
        title = wstring_block(std::vector<std::wstring>{months_names[month]});
        wstring_block temp = wstring_block(std::vector<std::wstring>{day_of_week[0]});
        for (int i = 1; i < 7; i++) {
            temp = merge_hor(temp, wstring_block(std::vector<std::wstring>{day_of_week[i]}), 1, HOR_ALIGH::UP);
        }
        title = merge_ver(title, temp, 0, VER_ALIGH::MID_L);
        break;
    }
    case LANG::RUS:
    {
        title = wstring_block(std::vector<std::wstring>{months_names_ru[month]});
        wstring_block temp = wstring_block(std::vector<std::wstring>{day_of_week_ru[0]});
        for (int i = 1; i < 7; i++) {
            temp = merge_hor(temp, wstring_block(std::vector<std::wstring>{day_of_week_ru[i]}), 1, HOR_ALIGH::UP);
        }
        title = merge_ver(title, temp, 0, VER_ALIGH::MID_L);
        break;
    }
    default:
        throw 1;
    }
    
    int day_now = 3;
    for (int i = 1970; i < year; i++)
        day_now = (day_now + 365 + is_leap(i)) % 7;
    const int this_year_is_leap = is_leap(year);
    for (int i = 0; i < month; i++) {
        day_now = (day_now + month_length[this_year_is_leap][i]) % 7;
    }
    std::vector<std::wstring> numbers;
    for (int i = 1; i <= month_length[this_year_is_leap][month]; i++) {
        if (i == 1 || day_now == 0) {
            numbers.push_back(std::wstring(2 * 7 + 6, L' '));
        }
        numbers.back()[3 * day_now + 1] = L'0' + i % 10;
        if (i / 10) {
            numbers.back()[3 * day_now] = L'0' + i / 10;
        }
        day_now = (day_now + 1) % 7;
    }
    wstring_block numbers_block(numbers);
    return merge_ver(title, numbers_block, 0, VER_ALIGH::MID_L);
}

wstring_block generate_title_number(int year, const title_number_font& t_font) {
    return t_font.gen(year);
}

wstring_block generate_calendar(int year, int H, LANG lang, const title_number_font& t_font) {
    int W = 12 / H;
    wstring_block res = generate_title_number(year, t_font);
    for (int i = 0; i < H; i++) {
        wstring_block row(0, 0);
        for (int j = 0; j < W; j++) {
            int month = i * W + j;
            wstring_block bl = generate_month(year, month, lang);
            if (j == 0) {
                row = bl;
            }
            else {
                row = merge_hor(row, bl, 4, HOR_ALIGH::UP);
            }
        }
        res = merge_ver(res, row, 1, VER_ALIGH::MID_R);
    }
    return res;
}

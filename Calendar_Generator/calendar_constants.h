#ifndef CALENDAR_CONSTANTS_H
#define CALENDAR_CONSTANTS_H

#include <vector>
#include <string>
#include "wstring_block.h"

extern const std::vector<std::wstring> months_names;
extern const std::vector<std::wstring> months_names_ru;
extern const std::vector<std::wstring> day_of_week;
extern const std::vector<std::wstring> day_of_week_ru;
extern const int month_length[2][12];
extern std::vector<wstring_block> font_3x5;
extern std::vector<wstring_block> font_ANSI_Regular;
extern std::vector<wstring_block> font_ANSI_Shadow;
extern std::vector<wstring_block> font_Fraktur;

#endif // !CALENDAR_CONSTANTS_H

#ifndef GENERATOR_H
#define GENERATOR_H

#include "calendar_constants.h"
#include "wstring_block.h"
#include "title_number_font.h"

enum class LANG {
    ENG,
    RUS
};

bool is_leap(int x);
wstring_block generate_month(int year, int month, LANG);
wstring_block generate_title_number(int year, const title_number_font&);
wstring_block generate_calendar(int year, int, LANG, const title_number_font&);

#endif // !GENERATOR_H

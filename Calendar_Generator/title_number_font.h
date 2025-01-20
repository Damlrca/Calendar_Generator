#ifndef TITLE_NUMBER_FONT_H
#define TITLE_NUMBER_FONT_H

#include <vector>
#include <string>
#include <cassert>
#include "wstring_block.h"

class title_number_font {
    std::vector<wstring_block> digits;
    int space;
    HOR_ALIGH hor_align;
public:
    title_number_font(const std::vector<wstring_block>& _dig, int _sp, HOR_ALIGH _hor_al) :
        digits{ _dig }, space{ _sp }, hor_align{ _hor_al } {
        assert(_dig.size() == 10);
    }
    wstring_block gen(int year) const {
        int a = year / 1000 % 10;
        int b = year / 100 % 10;
        int c = year / 10 % 10;
        int d = year % 10;
        wstring_block res = digits[a];
        res = merge_hor(res, digits[b], space, hor_align);
        res = merge_hor(res, digits[c], space, hor_align);
        res = merge_hor(res, digits[d], space, hor_align);
        return res;
    }
};

#endif // !TITLE_NUMBER_FONT_H

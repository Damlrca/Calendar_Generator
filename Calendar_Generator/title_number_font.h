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
        // TODO
        return wstring_block(0, 0);
    }
};

#endif // !TITLE_NUMBER_FONT_H

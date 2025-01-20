#include "generator.h"

wstring_block generate_month(int year, int month, LANG) {
	// todo
	return wstring_block(0, 0);
}

wstring_block generate_title_number(int year, const title_number_font& t_font) {
	return t_font.gen(year);
}

wstring_block generate_calendar(int year, int H, LANG, const title_number_font&) {
	// todo
	return wstring_block(0, 0);
}

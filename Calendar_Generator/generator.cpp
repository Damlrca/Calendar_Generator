#include "generator.h"

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
	
	wstring_block numbers(0, 0);
	// todo
	return merge_ver(title, numbers, 0, VER_ALIGH::MID_L);
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
				row = merge_hor(row, bl, 1, HOR_ALIGH::UP);
			}
		}
		res = merge_ver(res, row, 1, VER_ALIGH::MID_L);
	}
	return wstring_block(0, 0);
}

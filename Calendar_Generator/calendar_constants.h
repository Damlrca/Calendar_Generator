#ifndef CALENDAR_CONSTANTS_H
#define CALENDAR_CONSTANTS_H

#include <string>

const std::wstring months_names[]
{ L"January",L"February",
L"March",L"April",L"May",
L"June",L"July",L"August",
L"September",L"October",L"November",
L"December" };

const std::wstring months_names_ru[]
{ L"Январь",L"Февраль",
L"Март",L"Апрель",L"Май",
L"Июнь",L"Июль",L"Август",
L"Сентябрь",L"Октябрь",L"Ноябрь",
L"Декабрь" };

const std::wstring day_of_week[]
{
	L"MO",L"TU",L"WE",L"TH",L"FR",L"SA",L"SU"
};

const std::wstring day_of_week_ru[]
{
	L"ПН",L"ВТ",L"СР",L"ЧТ",L"ПТ",L"СБ",L"ВС"
};

const int month_length[2][12]{
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

const std::wstring big_digit[10][5]{
	{L"███",
	 L"█ █",
	 L"█ █",
	 L"█ █",
	 L"███"},

	{L" █ ",
	 L"██ ",
	 L" █ ",
	 L" █ ",
	 L"███"},

	{L"███",
	 L"  █",
	 L"███",
	 L"█  ",
	 L"███"},

	{L"███",
	 L"  █",
	 L"███",
	 L"  █",
	 L"███"},

	{L"█ █",
	 L"█ █",
	 L"███",
	 L"  █",
	 L"  █"},

	{L"███",
	 L"█  ",
	 L"███",
	 L"  █",
	 L"███"},

	{L"███",
	 L"█  ",
	 L"███",
	 L"█ █",
	 L"███"},

	{L"███",
	 L"  █",
	 L"  █",
	 L"  █",
	 L"  █"},

	{L"███",
	 L"█ █",
	 L"███",
	 L"█ █",
	 L"███"},

	{L"███",
	 L"█ █",
	 L"███",
	 L"  █",
	 L"███"}
};

#endif // !CALENDAR_CONSTANTS_H

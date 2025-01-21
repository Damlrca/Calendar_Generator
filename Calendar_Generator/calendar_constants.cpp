#include "calendar_constants.h"

extern const std::vector<std::wstring> months_names{
    L"January", L"February",
    L"March", L"April", L"May",
    L"June", L"July", L"August",
    L"September", L"October", L"November",
    L"December"
};

extern const std::vector<std::wstring> months_names_ru{
    L"Январь", L"Февраль",
    L"Март", L"Апрель", L"Май",
    L"Июнь", L"Июль", L"Август",
    L"Сентябрь", L"Октябрь", L"Ноябрь",
    L"Декабрь"
};

extern const std::vector<std::wstring> day_of_week{
    L"MO", L"TU", L"WE", L"TH", L"FR", L"SA", L"SU"
};

extern const std::vector<std::wstring> day_of_week_ru{
    L"ПН", L"ВТ", L"СР", L"ЧТ", L"ПТ", L"СБ", L"ВС"
};

extern const int month_length[2][12]{
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

extern std::vector<wstring_block> font_3x5{
    wstring_block(std::vector<std::wstring>{
     L"███",
     L"█ █",
     L"█ █",
     L"█ █",
     L"███"}),

    wstring_block(std::vector<std::wstring>{
     L" █ ",
     L"██ ",
     L" █ ",
     L" █ ",
     L"███"}),

    wstring_block(std::vector<std::wstring>{
     L"███",
     L"  █",
     L"███",
     L"█  ",
     L"███"}),

    wstring_block(std::vector<std::wstring>{
     L"███",
     L"  █",
     L"███",
     L"  █",
     L"███"}),

    wstring_block(std::vector<std::wstring>{
     L"█ █",
     L"█ █",
     L"███",
     L"  █",
     L"  █"}),

    wstring_block(std::vector<std::wstring>{
     L"███",
     L"█  ",
     L"███",
     L"  █",
     L"███"}),

    wstring_block(std::vector<std::wstring>{
     L"███",
     L"█  ",
     L"███",
     L"█ █",
     L"███"}),

    wstring_block(std::vector<std::wstring>{
     L"███",
     L"  █",
     L"  █",
     L"  █",
     L"  █"}),

    wstring_block(std::vector<std::wstring>{
     L"███",
     L"█ █",
     L"███",
     L"█ █",
     L"███"}),

    wstring_block(std::vector<std::wstring>{
     L"███",
     L"█ █",
     L"███",
     L"  █",
     L"███"})
};

extern std::vector<wstring_block> font_ANSI_Regular{
    wstring_block(std::vector<std::wstring>{
     L" ██████ ",
     L"██  ████",
     L"██ ██ ██",
     L"████  ██",
     L" ██████ "}),

    wstring_block(std::vector<std::wstring>{
     L" ██",
     L"███",
     L" ██",
     L" ██",
     L" ██"}),

    wstring_block(std::vector<std::wstring>{
     L"██████ ",
     L"     ██",
     L" █████ ",
     L"██     ",
     L"███████"}),

    wstring_block(std::vector<std::wstring>{
     L"██████ ",
     L"     ██",
     L" █████ ",
     L"     ██",
     L"██████ "}),

    wstring_block(std::vector<std::wstring>{
     L"██   ██",
     L"██   ██",
     L"███████",
     L"     ██",
     L"     ██"}),

    wstring_block(std::vector<std::wstring>{
     L"███████",
     L"██     ",
     L"███████",
     L"     ██",
     L"███████"}),

    wstring_block(std::vector<std::wstring>{
     L" ██████ ",
     L"██      ",
     L"███████ ",
     L"██    ██",
     L" ██████ "}),

    wstring_block(std::vector<std::wstring>{
     L"███████",
     L"     ██",
     L"    ██ ",
     L"   ██  ",
     L"   ██  "}),

    wstring_block(std::vector<std::wstring>{
     L" █████ ",
     L"██   ██",
     L" █████ ",
     L"██   ██",
     L" █████ "}),

    wstring_block(std::vector<std::wstring>{
     L" █████ ",
     L"██   ██",
     L" ██████",
     L"     ██",
     L" █████ "})
};

extern std::vector<wstring_block> font_ANSI_Shadow{
    wstring_block(std::vector<std::wstring>{
     L" ██████╗ ",
     L"██╔═████╗",
     L"██║██╔██║",
     L"████╔╝██║",
     L"╚██████╔╝",
     L" ╚═════╝ "}),

    wstring_block(std::vector<std::wstring>{
     L" ██╗",
     L"███║",
     L"╚██║",
     L" ██║",
     L" ██║",
     L" ╚═╝"}),

    wstring_block(std::vector<std::wstring>{
     L"██████╗ ",
     L"╚════██╗",
     L" █████╔╝",
     L"██╔═══╝ ",
     L"███████╗",
     L"╚══════╝"}),

    wstring_block(std::vector<std::wstring>{
     L"██████╗ ",
     L"╚════██╗",
     L" █████╔╝",
     L" ╚═══██╗",
     L"██████╔╝",
     L"╚═════╝ "}),

    wstring_block(std::vector<std::wstring>{
     L"██╗  ██╗",
     L"██║  ██║",
     L"███████║",
     L"╚════██║",
     L"     ██║",
     L"     ╚═╝"}),

    wstring_block(std::vector<std::wstring>{
     L"███████╗",
     L"██╔════╝",
     L"███████╗",
     L"╚════██║",
     L"███████║",
     L"╚══════╝"}),

    wstring_block(std::vector<std::wstring>{
     L" ██████╗ ",
     L"██╔════╝ ",
     L"███████╗ ",
     L"██╔═══██╗",
     L"╚██████╔╝",
     L" ╚═════╝ "}),

    wstring_block(std::vector<std::wstring>{
     L"███████╗",
     L"╚════██║",
     L"    ██╔╝",
     L"   ██╔╝ ",
     L"   ██║  ",
     L"   ╚═╝  "}),

    wstring_block(std::vector<std::wstring>{
     L" █████╗ ",
     L"██╔══██╗",
     L"╚█████╔╝",
     L"██╔══██╗",
     L"╚█████╔╝",
     L" ╚════╝ "}),

    wstring_block(std::vector<std::wstring>{
     L" █████╗ ",
     L"██╔══██╗",
     L"╚██████║",
     L" ╚═══██║",
     L" █████╔╝",
     L" ╚════╝ "})
};

extern std::vector<wstring_block> font_Fraktur{
    wstring_block(std::vector<std::wstring>{
     LR"(    .n~~%x.    )",
     LR"(  x88X   888.  )",
     LR"( X888X   8888L )",
     LR"(X8888X   88888 )",
     LR"(88888X   88888X)",
     LR"(88888X   88888X)",
     LR"(88888X   88888f)",
     LR"(48888X   88888 )",
     LR"( ?888X   8888" )",
     LR"(  "88X   88*`  )",
     LR"(    ^"==="`    )"}),

    wstring_block(std::vector<std::wstring>{
     LR"(      oe   )",
     LR"(    .@88   )",
     LR"(==*88888   )",
     LR"(   88888   )",
     LR"(   88888   )",
     LR"(   88888   )",
     LR"(   88888   )",
     LR"(   88888   )",
     LR"(   88888   )",
     LR"(   88888   )",
     LR"('**%%%%%%**)"}),

    wstring_block(std::vector<std::wstring>{
     LR"(  .--~*teu.   )",
     LR"( dF     988Nx )",
     LR"(d888b   `8888>)",
     LR"(?8888>  98888F)",
     LR"( "**"  x88888~)",
     LR"(      d8888*` )",
     LR"(    z8**"`   :)",
     LR"(  :?.....  ..F)",
     LR"( <""888888888~)",
     LR"( 8:  "888888* )",
     LR"( ""    "**"`  )"}),

    wstring_block(std::vector<std::wstring>{
     LR"(  .x~~"*Weu.  )",
     LR"( d8Nu.  9888c )",
     LR"( 88888  98888 )",
     LR"( "***"  9888% )",
     LR"(      ..@8*"  )",
     LR"(   ````"8Weu  )",
     LR"(  ..    ?8888L)",
     LR"(:@88N   '8888N)",
     LR"(*8888~  '8888F)",
     LR"('*8"`   9888% )",
     LR"(  `~===*%"`   )"}),

    wstring_block(std::vector<std::wstring>{
     LR"(        xeee   )",
     LR"(       d888R   )",
     LR"(      d8888R   )",
     LR"(     @ 8888R   )",
     LR"(   .P  8888R   )",
     LR"(  :F   8888R   )",
     LR"( x"    8888R   )",
     LR"(d8eeeee88888eer)",
     LR"(       8888R   )",
     LR"(       8888R   )",
     LR"(    "*%%%%%%**~)"}),

    wstring_block(std::vector<std::wstring>{
     LR"(  cuuu....uK   )",
     LR"(  888888888    )",
     LR"(  8*888**"     )",
     LR"(  >  .....     )",
     LR"(  Lz"  ^888Nu  )",
     LR"(  F     '8888k )",
     LR"(  ..     88888>)",
     LR"( @888L   88888 )",
     LR"('8888F   8888F )",
     LR"( %8F"   d888"  )",
     LR"(  ^"===*%"`    )"}),

    wstring_block(std::vector<std::wstring>{
     LR"(    .ue~~%u.  )",
     LR"(  .d88   z88i )",
     LR"( x888E  *8888 )",
     LR"(:8888E   ^""  )",
     LR"(98888E.=tWc.  )",
     LR"(98888N  '888N )",
     LR"(98888E   8888E)",
     LR"('8888E   8888E)",
     LR"( ?888E   8888")",
     LR"(  "88&   888" )",
     LR"(    ""==*""   )"}),

    wstring_block(std::vector<std::wstring>{
     LR"(dL ud8Nu  :8c)",
     LR"(8Fd888888L %8)",
     LR"(4N88888888cuR)",
     LR"(4F   ^""%""d )",
     LR"(d       .z8  )",
     LR"(^     z888   )",
     LR"(    d8888'   )",
     LR"(   888888    )",
     LR"(  :888888    )",
     LR"(   888888    )",
     LR"(   '%**%     )"}),

    wstring_block(std::vector<std::wstring>{
     LR"(   u+=~~~+u.   )",
     LR"( z8F      `8N. )",
     LR"(d88L       98E )",
     LR"(98888bu.. .@*  )",
     LR"("88888888NNu.  )",
     LR"( "*8888888888i )",
     LR"( .zf""*8888888L)",
     LR"(d8F      ^%888E)",
     LR"(88>        `88~)",
     LR"('%N.       d*" )",
     LR"(   ^"====="`   )"}),

    wstring_block(std::vector<std::wstring>{
     LR"(  .xn!~%x.    )",
     LR"( x888   888.  )",
     LR"(X8888   8888: )",
     LR"(88888   X8888 )",
     LR"(88888   88888>)",
     LR"(`8888  :88888X)",
     LR"(  `"**~ 88888>)",
     LR"( .xx.   88888 )",
     LR"('8888>  8888~ )",
     LR"( 888"  :88%   )",
     LR"(  ^"===""     )"}),
};

#include <algorithm>
#include "wstring_block.h"

static void put_wstring_inplace(std::vector<std::wstring>& res,
    const std::vector<std::wstring>& from,
    int x, int y, int H, int W) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            res[x + i][y + j] = from[i][j];
        }
    }
}

static int get_mid_l(int W, int a) {
    int diff = W - a;
    int l = diff / 2;
    int r = diff - l;
    return l;
}

static int get_mid_r(int W, int a) {
    int diff = W - a;
    int r = diff / 2;
    int l = diff - r;
    return l;
}

wstring_block merge_hor(wstring_block a, wstring_block b, int space, HOR_ALIGH hor_aligh) {
    int a_h = a.get_h();
    int a_w = a.get_w();
    const std::vector<std::wstring>& a_block = a.get_block();
    int b_h = b.get_h();
    int b_w = b.get_w();
    const std::vector<std::wstring>& b_block = b.get_block();
    int W = a_w + b_w + space;
    int H = std::max(a_h, b_h);
    std::vector<std::wstring> res(H, std::wstring(W, L' '));
    switch (hor_aligh) {
    case HOR_ALIGH::UP:
        put_wstring_inplace(res, a_block, 0, 0, a_h, a_w);
        put_wstring_inplace(res, b_block, 0, a_w + space, b_h, b_w);
        break;
    case HOR_ALIGH::DOWN:
        put_wstring_inplace(res, a_block, H - a_h, 0, a_h, a_w);
        put_wstring_inplace(res, b_block, H - b_h, a_w + space, b_h, b_w);
        break;
    case HOR_ALIGH::MID_L:
        put_wstring_inplace(res, a_block, get_mid_l(H, a_h), 0, a_h, a_w);
        put_wstring_inplace(res, b_block, get_mid_l(H, b_h), a_w + space, b_h, b_w);
        break;
    case HOR_ALIGH::MID_R:
        put_wstring_inplace(res, a_block, get_mid_r(H, a_h), 0, a_h, a_w);
        put_wstring_inplace(res, b_block, get_mid_r(H, b_h), a_w + space, b_h, b_w);
        break;
    default:
        throw 1;
    }
    return wstring_block(res);
}

wstring_block merge_ver(wstring_block a, wstring_block b, int space, VER_ALIGH ver_align) {
    int a_h = a.get_h();
    int a_w = a.get_w();
    const std::vector<std::wstring>& a_block = a.get_block();
    int b_h = b.get_h();
    int b_w = b.get_w();
    const std::vector<std::wstring>& b_block = b.get_block();
    int H = a_h + b_h + space;
    int W = std::max(a_w, b_w);
    std::vector<std::wstring> res(H, std::wstring(W, L' '));
    switch (ver_align) {
    case VER_ALIGH::LEFT:
        put_wstring_inplace(res, a_block, 0, 0, a_h, a_w);
        put_wstring_inplace(res, b_block, a_h + space, 0, b_h, b_w);
        break;
    case VER_ALIGH::RIGHT:
        put_wstring_inplace(res, a_block, 0, W - a_w, a_h, a_w);
        put_wstring_inplace(res, b_block, a_h + space, W - b_w, b_h, b_w);
        break;
    case VER_ALIGH::MID_L:
        put_wstring_inplace(res, a_block, 0, get_mid_l(W, a_w), a_h, a_w);
        put_wstring_inplace(res, b_block, a_h + space, get_mid_l(W, b_w), b_h, b_w);
        break;
    case VER_ALIGH::MID_R:
        put_wstring_inplace(res, a_block, 0, get_mid_r(W, a_w), a_h, a_w);
        put_wstring_inplace(res, b_block, a_h + space, get_mid_r(W, b_w), b_h, b_w);
        break;
    default:
        throw 1;
    }
    return wstring_block(res);
}

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
	// todo
	switch (hor_aligh) {
	case HOR_ALIGH::UP:
		break;
	case HOR_ALIGH::DOWN:
		break;
	case HOR_ALIGH::MID_L:
		break;
	case HOR_ALIGH::MID_R:
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
	// todo
	switch (ver_align) {
	case VER_ALIGH::LEFT:
		break;
	case VER_ALIGH::RIGHT:
		break;
	case VER_ALIGH::MID_L:
		break;
	case VER_ALIGH::MID_R:
		break;
	default:
		throw 1;
	}
	return wstring_block(res);
}

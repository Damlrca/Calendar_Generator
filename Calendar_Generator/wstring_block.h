#ifndef WSTRING_BLOCK_H
#define WSTRING_BLOCK_H

#include <vector>
#include <string>
#include <cassert>

enum class HOR_ALIGH {
    UP,
    DOWN,
    MID_L,
    MID_R
};

enum class VER_ALIGH {
    LEFT,
    RIGHT,
    MID_L,
    MID_R
};

class wstring_block {
    std::vector<std::wstring> block;
    int h, w;
public:
    wstring_block(int H, int W) : h{ H }, w{ W } {
        block = std::vector<std::wstring>(H, std::wstring(W, L' '));
    }
    wstring_block(std::vector<std::wstring> _bl) : block(_bl), h{ (int)_bl.size() } {
        if (block.size() == 0) {
            w = 0;
        }
        else {
            w = block[0].size();
            for (int i = 0; i < h; i++) {
                assert(block[i].size() == w);
            }
        }
    }
    int get_h() {
        return h;
    }
    int get_w() {
        return w;
    }
    const std::vector<std::wstring>& get_block() {
        return block;
    }
};

wstring_block merge_hor(wstring_block, wstring_block, int, HOR_ALIGH);

wstring_block merge_ver(wstring_block, wstring_block, int, VER_ALIGH);

#endif // !WSTRING_BLOCK_H

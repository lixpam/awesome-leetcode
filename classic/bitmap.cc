#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * 位图
 */

class BitMap
{
public:
    BitMap(int max) {
        int cap = ((max >> 3) + 1) * sizeof(unsigned char);
        bm = (unsigned char*)malloc(cap);
    }

    ~BitMap() {
        free(bm);
    }

    // 设置位
    void set(int num) {
        bm[num >> 3] |= (1 << (num & 0x07));
    }
    
    // 清空位
    void clear(int num) {
        bm[num >> 3] &= ~(1 << (num & 0x07));
    }

    // 判断位是否设置
    bool exist(int num) {
        return (bm[num >> 3] & (1 << (num & 0x07))) != 0;
    }

private:
    unsigned char *bm;
};

int main()
{
    BitMap bm(100);
    for (int i = 4; i < 16; ++i) {
        bm.set(i);
    }

    bm.clear(9);

    for (int i = 0; i < 16; ++i) {
        if (!bm.exist(i)) {
            printf("%d not exist\n", i);
        }
    }

    return 0;
}

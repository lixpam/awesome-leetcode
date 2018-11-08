#include <iostream>
#include <vector>
using namespace std;

/*
 * 排列算法
 *           123
 *   123     213     321
 * 123 132 213 231 321 312
 * 可以看成一棵树，第一层是list中第一个数分别和其他位置数交换(包括自己)
 * 第二层是第二个位置数分别和之后的数交换(包括自己)
 */

void perm(vector<int> &list, int k, int m) {
    if (k > m) {
        for (auto it : list) {
            cout << it << " ";
        }
        cout << endl;
    } else {
        for (int i = k; i <= m; ++i) {
            swap(list[k], list[i]);
            perm(list, k+1, m);
            swap(list[k], list[i]);
        }
    }
}

/*
 * 组合算法
 *           1234
 *   1         2       3      4
 *  2 3 4    3   4     4
 * 可以看成一棵树，第一层是list中所有的数
 * 第二层是当前数之后的树
 * 再有就继续
 */

void comb(vector<int> &list, int l_start, int *result, int r_start, int n) {
    if (r_start == n) {
        for (int i = 0; i < n; ++i) {
            cout << result[i] << " ";
        }
        cout << endl;
    } else {
        int len = list.size();
        for (int i = l_start; i < len-n+r_start; ++i) {
            result[r_start] = list[i];
            comb(list, i+1, result, r_start+1, n);
        }
    }
}

int main()
{
    vector<int> list{1,2,3,4};
    //perm(list, 0, 3);
    int result[2] = {0};
    comb(list, 0, result, 0, 2);
}

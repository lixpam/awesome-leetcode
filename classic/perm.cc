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

/*
 * 下一个排列
 * 1. 从数列右边向左寻找连续递增序列，譬如 1 3 5 4 2，则542就是连续递增序列
 * 2. 从上述递增序列中寻找大于其前一个数的最小数，并交换这两个数，譬如上面13 542->14 532, 交换后还是递增序列
 * 3. 新的递增序列逆序, 14532->14235
 */

bool nextPerm(vector<int> &list) {
    int i, j, k;
    int len = list.size();
    for (k = len-1; k > 0 && list[k-1] >= list[k]; --k);
    if (k == 0) return false;       // 达到最后一个排列，没有下个，返回false；例如3 2 1

    for (i = len-1; list[k-1] >= list[i]; --i);     // 找到递增序列的最小大于k-1位置的树
    swap(list[k-1], list[i]);    // 交换 

    i = k, j = len-1;
    while (i < j) swap(list[i++], list[j--]);
    return true;
}

int main()
{
    vector<int> list{1,2,3,4};
    //perm(list, 0, 3);
    //int result[2] = {0};
    //comb(list, 0, result, 0, 2);
    nextPerm(list);
    for (auto it : list) {
        cout << it << " ";
    }
    cout << endl;
}

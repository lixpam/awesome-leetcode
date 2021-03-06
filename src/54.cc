#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowmin = 0, colmin = 0;
        int rowmax = matrix.size()-1;
        if (rowmax < 0) return {};
        int colmax = matrix[0].size()-1;
        if (colmax < 0) return {};

        int total = (rowmax+1)* (colmax+1);
        vector<int> ret(total, 0);
        int x = 0, y = -1, pos = 0;
        while (pos < total) {
            while (++y <= colmax) {
                ret[pos++] = matrix[x][y];
            }
            if (pos >= total) break;
            y--;
            rowmin++;
            while (++x <= rowmax) {
                ret[pos++] = matrix[x][y];
            }
            if (pos >= total) break;
            x--;
            colmax--;
            while (--y >= colmin) {
                ret[pos++] = matrix[x][y];
            }
            if (pos >= total) break;
            y++;
            rowmax--;
            while (--x >= rowmin) {
                ret[pos++] = matrix[x][y];
            }
            if (pos >= total) break;
            x++;
            colmin++;
        }
        return ret;
    }
};

int main()  {
    Solution s;
    vector<vector<int>> mt = {
        {1},
        {2},
        {3},
        {4},
        {5},
        {6},
        {7},
        {8},
        {9},
        {10},
    };

    vector<int> ret = s.spiralOrder(mt);
    cout << ret.size() << endl;
    for (auto &it : ret) {
         cout << it << " ";
    }
    cout << endl;
}

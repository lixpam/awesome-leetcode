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
        int rowmin = 0, colmin = 0, rowmax = matrix.size()-1, colmax = matrix[0].size()-1;

        int total = (rowmax+1)* (colmax+1);
        vector<int> ret(total, 0);
        int x = 0, y = 0, pos = 0;
        while (pos < total) {
            while (y <= colmax) {
                ret[pos++] = matrix[x][y];
                y++;
            }
            y--;
            x++;
            rowmin++;
            while (x <= rowmax) {
                ret[pos++] = matrix[x][y];
                x++;
            }
            x--;
            y--;
            colmax--;
            while (y >= colmin) {
                ret[pos++] = matrix[x][y];
                y--;
            }
            y++;
            x--;
            rowmax--;
            while (x >= rowmin) {
                ret[pos++] = matrix[x][y];
                x--;
            }
            x++;
            y++;
            colmin++;
        }
        return ret;
    }
};

int main()  {
    Solution s;
    vector<vector<int>> mt = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    vector<int> ret = s.spiralOrder(mt);
    cout << ret.size() << endl;
    for (auto &it : ret) {
         cout << it << " ";
    }
    cout << endl;
}

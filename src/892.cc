#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:

    int surfaceArea(vector<vector<int>>& grid) {
        int ret = 0;
        const int a[][2] = {{1, 0}, {0,1}};

        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        if (col == 0) return 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 0) continue;
                ret += 4*grid[i][j] + 2;
                for (int k = 0; k < 2; ++k) {
                    int _x = i + a[k][0];
                    int _y = j + a[k][1];
                    if (_x >= 0 && _x < row && _y >= 0 && _y < col) {
                        ret -= 2*min(grid[i][j], grid[_x][_y]);
                    }
                }
            }
        }
        return ret;
    }
};

int main()  {
    Solution s;
    vector<vector<int>> p{{2,2,2},{2,1,2},{2,2,2}};
    cout << s.surfaceArea(p) << endl;
}

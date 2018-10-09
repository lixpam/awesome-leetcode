#include <iostream>
#include <vector>

using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dy[m][n] = {0};
        dy[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dy[i][0] = dy[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < n; ++i) {
            dy[0][i] = dy[0][i-1] + grid[0][i];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dy[i][j] = min(dy[i-1][j], dy[i][j-1]) + grid[i][j];
            }
        }
        return dy[m-1][n-1];
    }
};


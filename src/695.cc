#include "../tools/luban.h"
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int& sum, vector<vector<bool>>& visited) {
        if (r < 0 || r >= grid.size()) return;
        if (c < 0 || c >= grid[0].size()) return;

        if (grid[r][c] == 0 || visited[r][c]) return;

        visited[r][c] = true;
        sum++;
        dfs(grid, r-1, c, sum, visited);
        dfs(grid, r+1, c, sum, visited);
        dfs(grid, r, c-1, sum, visited);
        dfs(grid, r, c+1, sum, visited);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col= grid[0].size();
        if (col == 0) return 0;

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int sum = 0;
        for (int i = 0; i < row; ++i){
            for (int j = 0; j <col; ++j){
                if (grid[i][j] == 0 || visited[i][j]) continue;
                int _sum = 0;
                dfs(grid, i, j, _sum, visited);
                sum = max(_sum, sum);
            }
        }
        return sum;
    }
};

int main()  {
    Solution s;

    vector<vector<int>> matrix = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
     {0,0,0,0,0,0,0,1,1,1,0,0,0},
     {0,1,1,0,1,0,0,0,0,0,0,0,0},
     {0,1,0,0,1,1,0,0,1,0,1,0,0},
     {0,1,0,0,1,1,0,0,1,1,1,0,0},
     {0,0,0,0,0,0,0,0,0,0,1,0,0},
     {0,0,0,0,0,0,0,1,1,1,0,0,0},
     {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    cout << s.maxAreaOfIsland(matrix) << endl;
}

#include "../tools/luban.h"
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited){
        if (r < 0 || r >= grid.size()) return;
        if (c < 0 || c >= grid[0].size()) return;

        if (grid[r][c] == '0' || visited[r][c]) return;

        visited[r][c] = true;
        dfs(grid, r+1, c, visited);
        dfs(grid, r-1, c, visited);
        dfs(grid, r, c-1, visited);
        dfs(grid, r, c+1, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        if (col == 0) return 0;

        int cnt = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '0' || visited[i][j]) continue;

                dfs(grid, i, j, visited);
                cnt++;
            }
        }
        return cnt;
    }
};

int main()  {
    Solution s;
    vector<vector<char>> matrix1 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    cout << s.numIslands(matrix1) << endl;

    vector<vector<char>> matrix2 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout << s.numIslands(matrix2) << endl;
}

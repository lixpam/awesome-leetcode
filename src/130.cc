#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        vector<vector<int>> flag(m, vector<int>(n, 1));
        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    if (i == 0 || i == m-1 || j == 0 || j == n-1) {
                        flag[i][j] = 0;
                        q.push({i, j});
                    }
                }
            }
        }

        while (!q.empty()) {
            auto &it = q.front();
            q.pop();

            int x = it.first, y = it.second;
            if (x > 0) {
                if (board[x-1][y] == 'O' && flag[x-1][y] != 0) {
                    flag[x-1][y] = 0;
                    q.push({x-1, y});
                }
            }
            if (x < m-1) {
                if (board[x+1][y] == 'O' && flag[x+1][y] != 0) {
                    flag[x+1][y] = 0;
                    q.push({x+1, y});
                }
            }
            if (y > 0) {
                if (board[x][y-1] == 'O' && flag[x][y-1] != 0) {
                    flag[x][y-1] = 0;
                    q.push({x, y-1});
                }
            }
            if (y < n-1) {
                if (board[x][y+1] == 'O' && flag[x][y+1] != 0) {
                    flag[x][y+1] = 0;
                    q.push({x, y+1});
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (flag[i][j] != 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main()
{
    Solution s;

    vector<vector<char>> arg1{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    vector<vector<char>> arg2{
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    s.solve(arg1);
    s.solve(arg2);

    for (auto &row : arg1) {
        for (auto &col : row){
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (auto &row : arg1) {
        for (auto &col : row){
            cout << col << " ";
        }
        cout << endl;
    }
}

#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] == matrix[0][0] == '1' ? 1 : 0;
        int _max = 0;
        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            _max = max(dp[i][0], _max);
        }
        for (int i = 0; i < n; ++i) {
            dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
            _max = max(dp[0][i], _max);
        }

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    int _min = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]);
                    dp[i][j] = _min == 0 ? 1 : (_min+1);
                    _max = max(_max, dp[i][j]);
                }
            }
        return _max * _max;
    }
};

int main()  {
    Solution s;
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','1','0','1'}
    };

    cout << s.maximalSquare(matrix) << endl;
}

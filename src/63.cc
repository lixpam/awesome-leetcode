#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        if (obstacleGrid[0][0] == 1) return 0;

        vector<vector<unsigned int>> dp(m, vector<unsigned int>(n));
        dp[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = dp[i-1][0];
            }
        }
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[0][i] == 1) {
                dp[0][i] = 0;
            } else {
                dp[0][i] = dp[0][i-1];
            }
        }

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        return dp[m-1][n-1];
    }
};

int main()  {
    Solution s;
    vector<vector<int>> nums = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 1, 0}
    };
    cout << s.uniquePathsWithObstacles(nums) << endl;
}

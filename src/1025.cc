#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

/* 动态规划解法
class Solution {
public:
    bool checkN(int x, vector<int>& dp) {
        int m = sqrt(double(x));
        for (int i = 1; i <= m; ++i) {
            if (x % i == 0)
                if (!dp[x-i]) return true;
        }
        return false;
    }
    bool divisorGame(int N) {
        if (N<=1) return false;
        vector<int> dp(N+1);
        dp[0] = false, dp[1] = false;
        for (int i = 2; i <= N; ++i) {
            dp[i] = checkN(i, dp);
        }
        return dp[N];
    }
};
*/

// 占2赢
class Solution {
public:
    bool divisorGame(int N) {
        return N%2==0;
    }
};

int main()  {
    Solution s;
}

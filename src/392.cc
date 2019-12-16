#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

/*
 * 动态规划，设置dp[i][j]为s[0...i]是否为t[0...j]的子序列
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        if (n <= 0) return true;
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        for (int i = 1; i <= m; ++i)
            if (s[0] == t[i-1])
                dp[1][i] = true;
            else
                dp[1][i] = dp[1][i-1];
        
        for (int i = 0; i <= m; ++i)
            cout << dp[1][i] << endl;

        for(int i = 1; i <= m; ++i) {
            for (int j = 2; j <= n; ++j) {
                if (t[i-1] == s[j-1])
                    dp[j][i] = dp[j-1][i-1];
                else {
                    dp[j][i] = dp[j][i-1];
                }
            }
        }
        return dp[n][m];
    }
};
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        if (n <= 0) return true;
        
        int i = n-1,j = m-1;
        while (i >= 0 && j >= 0) {
            if (s[i] == t[j])
                i--, j--;
            else
                j--;
        }
        return i<0;
    }
};

int main()  {
    Solution s;
    string t1 = "abc";
    string t2 = "ahbgdc";
    cout << s.isSubsequence(t1, t2) << endl;
}

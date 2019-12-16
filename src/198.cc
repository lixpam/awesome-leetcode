#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        vector<int> dp(len+1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= len; ++i) {
            dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        }
        return dp[len];
    }
};

int main()  {
    Solution s;
}

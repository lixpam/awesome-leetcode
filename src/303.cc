#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

/*
 * Accept, 时间和空间复杂度都很高，时间O(N), 空间O(N^2)
class NumArray {
public:
    NumArray(vector<int>& nums):mVals(nums) {
        int len = nums.size();
        dp.resize(len, vector<int>(len, INT_MIN));
        for (int i = 0; i < len; ++i) {
            dp[i][i] = nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (i == j) return dp[i][j];
        for (int x = i; x <= j; ++x) {
            if (dp[i][x] != INT_MIN && dp[x][j] != INT_MIN) {
                return dp[i][x] - mVals[x] + dp[x][j];
            }
        }
        dp[i][j] = accumulate(mVals.begin()+i, mVals.begin()+j+1, 0);
        return dp[i][j];
    }
private:
    vector<int> mVals;
    vector<vector<int>> dp;
};
*/

// 时间复杂度O(1), 空间复杂度O(N)
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int len = nums.size();
        dp.resize(len+1, 0);
        for (int i = 1; i <= len; ++i) {
            dp[i] = dp[i-1]+nums[i-1];
        }
    }

    int sumRange(int i, int j) {
        return dp[j+1] - dp[i];
    }
private:
    vector<int> dp;
};

int main()  {
    NumArray s;
}

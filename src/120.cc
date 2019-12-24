#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <set>
#include <unordered_set>
using namespace std;

//dp

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int _trav(vector<vector<int>>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return INT_MAX;
        if (i >= nums.size()) return INT_MAX;
        if (j >= nums[i].size()) return INT_MAX;

        if (dp[i][j] != INT_MAX) return dp[i][j];

        int min1 = _trav(nums, i-1, j-1, dp);
        int min2 = _trav(nums, i-1, j, dp);
        if (min1 == INT_MAX && min2 == INT_MAX) {
            dp[i][j] = nums[i][j];
        } else {
            dp[i][j] = min(min1, min2) + nums[i][j];
        }
        return dp[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        if (len == 0) return 0;
        vector<vector<int>> dp;
        for (auto &it : triangle) {
            dp.push_back(vector<int>(it.size(), INT_MAX));
        }
        dp[0][0] = triangle[0][0];
        for (int i = 0; i < triangle[len-1].size(); ++i) {
            _trav(triangle, len-1, i, dp);
        }
        int _min = INT_MAX;
        for (auto &it : dp[len-1]) {
            if (it < _min) {
                _min = it;
            }
        }
        return _min;
    }
};

/*
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        for (auto &iter : triangle) {
            dp.push_back(vector<int>(iter.size(), 0));
        }
        int size = triangle.size();
        if (size == 0) return 0;

        dp[0][0] = triangle[0][0];
        for (int i = 1; i < size; ++i) {
            int row = triangle[i].size();
            dp[i][0] = dp[i-1][0] + triangle[i][0];
            if (row > triangle[i-1].size()) {
                dp[i][row-1] = dp[i-1][row-2] + triangle[i][row-1];
                row--;
            }
            for (int j = 1; j < row; ++j){
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
        int _min = INT_MAX;
        for (auto &iter : dp[size-1]) {
            _min = min(_min, iter);
        }
        return _min;
    }
};
*/

int main()  {
    Solution s;
    vector<vector<int>> p = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    cout << s.minimumTotal(p) << endl;
}

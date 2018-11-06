#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <limits.h>
using namespace std;

// DP

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) return 0;
        if (len == 1) return nums[0];

        int _min = nums[0], _max = nums[0];
        int ret = nums[0];
        for (int i = 1; i < len; ++i) {
            int temp = _max;
            _max = max(max(_min * nums[i], _max*nums[i]), nums[i]);
            _min = min(min(_min * nums[i], temp*nums[i]), nums[i]);
            if (_max > ret) {
                ret = _max;
            }
        }
        return ret;
    }
};

int main()  {
    Solution s;
    vector<int> p{-2,3,-4};
    cout << s.maxProduct(p) << endl;
}

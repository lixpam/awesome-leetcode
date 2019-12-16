#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) return 0;
        int ret = INT_MIN;
        int dp = -1;
        for (int i = 0; i < len; ++i) {
            dp = max(dp + nums[i], nums[i]);
            ret = max(dp, ret);
        }
        return ret;
    }
};

int main()  {
    Solution s;
    vector<int> a{-2,1,-3,4,-1,2,-5,4};
    cout << s.maxSubArray(a) << endl;
}

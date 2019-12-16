#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        if (r <= 2) return accumulate(nums.begin(), nums.end(), 0);

        sort(nums.begin(), nums.end());
        int ret = nums[0]+nums[1]+nums[2];
        for (int i = 0; i < r-1; ++i) {
            int _l = i+1, _r = r;
            while (_l < _r) {
                int sum = nums[i] + nums[_l] + nums[_r];
                if (abs(sum-target) < abs(ret-target))
                    ret = sum;
                if (sum > target)
                    _r--;
                else if (sum == target)
                    return sum;
                else
                    _l++;
            }
        }
        return ret;
    }
};

int main()  {
    Solution s;
    //vector<int> nums{-1,1,-4,2};
    //vector<int> nums{-3,-2,-5,3,-4};
    vector<int> nums{1,2,4,8,16,32,64,128};
    cout << s.threeSumClosest(nums, 82) << endl;
}

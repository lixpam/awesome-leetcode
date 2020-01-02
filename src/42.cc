#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int trap(vector<int>& nums) {
        int len = nums.size();
        vector<int> max_left(nums), max_right(nums);
        for (int i = 1; i <len; ++i) {
            max_left[i] = max(max_left[i-1], max_left[i]);
        }
        for (int i = len-2; i >= 0; --i) {
            max_right[i] = max(max_right[i+1], max_right[i]);
        }
        int cnt = 0;
        for (int i = 0; i <len; ++i){
            cnt += min(max_left[i], max_right[i]) - nums[i];
        }
        return cnt;
    }
};

int main()  {
    Solution s;
    //vector<int> nums{0,1,0,2,1,0,1,3,2,1,2,1};  // 6
    //vector<int> nums{5,4,1,2};    // 1
    //vector<int> nums{0,2,1,1};
    //vector<int> nums{9,6,8,8,5,6,3}; // 3
    vector<int> nums{5,2,1,2,1,5}; // 3
    cout << s.trap(nums) << endl;
}

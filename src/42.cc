#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

/*
class Solution {
public:
    int trap(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        if (r <=1) return 0;

        int sum = 0;
        while (l < r) {
            while (l<r && nums[l] <= nums[l+1]) l++;
            while (l<r && nums[r-1] >= nums[r]) r--;

            int p = l+1;
            for (; p<r; ++p) {
                if (nums[p] >= nums[l]) break;
            }
            while (l<p && nums[l] > nums[p] && nums[l+1]>nums[p]) l++;

            sum += (p-l-1)*min(nums[l], nums[p]);
            sum -= accumulate(nums.begin()+l+1, nums.begin()+p, 0);
            l = p;
        }
        return sum;
    }
};
*/

class Solution {
public:
    int trap(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        if (r <=1) return 0;

        int sum = 0;
        while (l < r) {
            while (l<r && nums[l] <= nums[l+1]) l++;
            //while (l<r && nums[r-1] >= nums[r]) r--;

            int p = l+1;
            for (; p<r; ++p) {
                if (nums[p] > nums[p-1]) break;
            }
            for (; p<r; ++p) {
                if (nums[p] > nums[p+1]) break;
            }
            while (l<p && nums[l] > nums[p] && nums[l+1]>nums[p]) l++;
            
            sum += (p-l-1)*min(nums[l], nums[p]);
            sum -= accumulate(nums.begin()+l+1, nums.begin()+p, 0);
            cout << l << "->" << p << " " << sum << endl;
            l = p;
        }
        return sum;
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

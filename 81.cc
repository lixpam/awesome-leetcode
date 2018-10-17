#include <iostream>
#include <vector>
using namespace std;

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return false;
        int lo = 0, hi = len-1;
        while (lo < hi) {
            int mid = (hi+lo)/2;
            if (nums[mid] == target) return true;

            if (nums[lo] > nums[mid]) {
                // mid.end sort
                if (nums[mid] < target && target <= nums[hi]) {
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            } else if (nums[lo] < nums[mid]) {
                // lo.mid sort
                if (target < nums[mid] && target >= nums[lo]) {
                    hi = mid-1;
                } else {
                    lo = mid+1;
                }
            } else {
                lo++;
            }
        }

        return lo == hi && nums[lo] == target;
    }
};

int main()
{
    vector<int> arg{2,5,6,0,0,1,2};
    Solution s;
    cout << s.search(arg, 0) << endl;
    cout << s.search(arg, 3) << endl;
}

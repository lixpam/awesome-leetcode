#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        if (r <= 0) return;

        while (l < r) {
            while (r>=0 && nums[r] == 2) r--;
            while (l<nums.size() && nums[l] == 0) l++;
            if (l >= r) break;
            if (nums[l] == 2)
                swap(nums[l],nums[r--]);
            else if (nums[l] == 1) {
                if (nums[r] == 0) {
                    swap(nums[l++],nums[r]);
                } else {
                    int p = l+1;
                    while (p<=r) {
                        if (nums[p] == 0) {
                            swap(nums[l], nums[p]);
                            break;
                        } else if (nums[p] == 2) {
                            swap(nums[p], nums[r--]);
                            while (nums[r] == 2) r--;
                        } else {
                            p++;
                        }
                    }
                    l++;
                }
            }
        }
    }
};

/*
 * 三指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, curr=0,r=nums.size()-1;
        while (curr<=r) {
            if (nums[curr] == 0)
                swap(nums[l++], nums[curr++]);
            else if (nums[curr] == 2)
                swap(nums[curr], nums[r--]);
            else
                curr++;
        }
    }
};
 */

int main()  {
    Solution s;
    //vector<int> nums{1,2,2,2,2,0,2,0,1,1};
    vector<int> nums{2,0,2,1,1,0};
    s.sortColors(nums);

    prints(nums);
}

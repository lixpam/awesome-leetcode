#include "../tools/luban.h"
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> reverts;
        int len = nums.size();
        int sum_max = 0;
        int curr_sum = 0;
        for (int j = 0; j < len; ++j) {
            if (nums[j] == 1) {
                curr_sum++;
            } else if (k > 0) {
                reverts.push(j);
                k--;
                curr_sum++;
            } else {
                sum_max = curr_sum > sum_max ? curr_sum : sum_max;
                if (reverts.size() == 0) {
                    curr_sum = 0;
                } else {
                    int prev0 = reverts.front();
                    reverts.pop();
                    curr_sum = curr_sum - (prev0 - (j - curr_sum));
                    reverts.push(j);
                }
            }
        }

        return curr_sum > sum_max ? curr_sum : sum_max;
    }
};

/*
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = nums.size();
        int l = 0, r = 0;
        int sum_max = 0;
        while (l < len && r < len) {
            if (nums[r] == 1) {
                sum_max = max(sum_max, r-l+1);
                r++;
            } else {
                if (k > 0) {
                    sum_max = max(sum_max, r-l+1);
                    k--;
                    r++;
                } else {
                    if (nums[l] == 0)
                        k++;
                    l++;
                }
            }
        }

        return sum_max;
    }
};
*/

int main()  {
    Solution s;
    vector<int> nums{1,0,1,0,1,0,0,1,1,0,0};
    cout << s.longestOnes(nums, 0) << endl;
}

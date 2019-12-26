#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;

        int i = 0;
        while (i < len) {
            if (nums[i] >= len || nums[i] == i) {
                i++;
                continue;
            }

            swap(nums[nums[i]], nums[i]);
        }
        for (int i = 0; i < len; ++i)
            if (nums[i] != i){
                return i;
            }
        return len;
    }
};

int main()  {
    Solution s;
    vector<int> nums{9,6,4,2,3,5,7,0,1};
    cout << s.missingNumber(nums) << endl;
    for (auto &iter : nums)
        cout << iter << " ";
    cout << endl;
}

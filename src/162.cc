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
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[len-1] > nums[len-2]) return len-1;
        for (int i = 1; i < len-1; ++i) {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        }
        return len-1;
    }
};

int main()  {
    Solution s;
    vector<int> p{1,2,1,3,5,6,4};
    cout << s.findPeakElement(p) << endl;
}

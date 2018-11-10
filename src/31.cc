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
#include "../tools/print.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k, i;
        int len = nums.size();
        if (len <= 1) return;

        for (k = len-1; k > 0 && nums[k-1] >= nums[k]; --k);
        if (k != 0) {
            for (i = len-1; nums[k-1] >= nums[i]; --i);
            swap(nums[k-1], nums[i]);
        }
        
        while (k < --len) {
            swap(nums[k++], nums[len]);
        }
    }
};

int main()  {
    Solution s;
    vector<int> p{1,1,5};
    s.nextPermutation(p);
    SeqPrint::print<decltype(p)>(p);
}

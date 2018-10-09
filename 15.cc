#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < len-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] > 0) continue;
            for (int j = i + 1; j < len-1; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int left = 0-nums[i]-nums[j];
                if (nums[j] > left || left > nums[len-1]) continue;
                auto it = mp.find(left);
                if (it != mp.end() && it->second > j) {
                    ret.push_back(vector<int>{nums[i], nums[j], left});
                } 
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> n{1,1,-2};
    Solution s;
    vector<vector<int>> ret = s.threeSum(n);
    for (auto &oit : ret) {
        for (auto &iit : oit) {
            cout << iit << " ";
        }
        cout << endl;
    }

    return 0;
}

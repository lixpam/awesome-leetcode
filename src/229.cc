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

//boyer-moore majority vote algorithm
// 摩尔投票算法

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size()/3;
        int m1, cnt1 = 0, m2, cnt2 = 0;
        for (auto &it : nums) {
            if (cnt1 > 0 && m1 == it) {
                cnt1++;
                continue;
            }
            if (cnt2 > 0 && m2 == it) {
                cnt2++;
                continue;
            }

            if (cnt1 == 0) {
                m1 = it;
            } else if (cnt2 == 0) {
                m2 = it;
            }

            if (m1 == it) {
                cnt1++;
            } else if (m2 == it) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        if (cnt1 > 0 && cnt2 > 0 && m1 == m2) cnt2 = 0;
        vector<int> ret;
        if (cnt1 > 0) {
            if (count_if(nums.begin(), nums.end(), bind2nd(equal_to<int>(), m1)) > n) {
                ret.push_back(m1);
            }
        }
        if (cnt2 > 0) {
            if (count_if(nums.begin(), nums.end(), bind2nd(equal_to<int>(), m2)) > n) {
                ret.push_back(m2);
            }
        }
        return ret;
    }
};

int main()  {
    Solution s;

    //vector<int> p = {-1,1,1,1,2,1};
    vector<int> p = {1,2,2,3,2,1,1,3};
    vector<int> ret = s.majorityElement(p);
    for (auto &it : ret) {
        cout << it << " ";
    }
    cout << endl;
}

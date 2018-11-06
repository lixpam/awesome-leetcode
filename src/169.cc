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

// boyer-moore majority vote algorithm

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m, cnt = 0;
        for (auto &it : nums) {
            m = it;
            cnt = 1;
        } else if (m == it) {
            cnt++;
        } else {
            cnt--;
        }
    }
    return m;
};

int main()  {
    Solution s;
}

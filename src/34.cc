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

static vector<int> notfound{-1,-1};

class Solution {
public:
    bool findIndex(vector<int> &nums, int start, int end, int target, int &lp, int &rp) {
        if (start > end) return false;
        // for array is asc
        if (target < nums[start] || nums[end] < target) return false;
        if (start == end) {
            if (nums[start] == target) {
                lp = rp = start;
                return true;
            }
            return false;
        }

        int mid = (start+end)/2;
        int llp, lrp, rlp, rrp;
        bool lexist = findIndex(nums, start, mid, target, llp, lrp);
        bool rexist = findIndex(nums, mid+1, end, target, rlp, rrp);

        if (lexist && rexist) {
            lp = llp;
            rp = rrp;
        } else {
            lp = lexist ? llp : rlp;
            rp = lexist ? lrp : rrp;
        }

        return lexist || rexist;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int size= nums.size();
        if (size <= 0) return notfound;
        if (size == 1) {
            return nums[0] == target ? vector<int>{0, 0} : notfound;
        }

        int s, e;
        if (findIndex(nums, 0, size-1, target, s, e)) {
            return {s,e};
        } else {
            return notfound;
        }
    }
};

int main()  {
    Solution s;

    vector<int> p{5,5};
    vector<int> ret = s.searchRange(p, 5);
    for (auto &it : ret) {
        cout << it << " ";
    }
    cout << endl;
}

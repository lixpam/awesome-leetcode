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
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return len;

        int retLen = len;
        int last = nums[0], rep = 1;
        for (int i = 1; i < retLen; ++i) {
            if (nums[i] == last) {
                if (rep == 2) {
                    for (int j = i+1; j < retLen; ++j) {
                        nums[j-1] = nums[j];
                    }
                    retLen--;
                    i--;
                } else {
                    rep++;
                }
            } else {
                last = nums[i];
                rep = 1;
            }
        }
        return retLen;
    }
};

int main()  {
    Solution s;
    vector<int> p{0,0,1,1,2,3,3};
    int len = s.removeDuplicates(p);
    for (int i = 0; i < len; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
}

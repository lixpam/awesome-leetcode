#include "../tools/luban.h"
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

        int ret = 0;
        int l = 0, r = 1;
        while (r < len) {
            while (nums[r] == nums[l]) {
                r++;
                if (r >= len) break;
            }
            nums[ret] = nums[l];
            ret++;
            l = r++;
        }
        if (l < len) {
            nums[ret] = nums[l];
            ret++;
        }
        return ret;
    }
};

int main()  {
    Solution s;
    vector<int> p{1,2,2};
    int t = s.removeDuplicates(p);
    for (int i = 0; i < t; ++i)
        cout << p[i] << " ";
    cout << endl;

    vector<int> p1{0,0,1,1,2,2,3,3,4};
    t = s.removeDuplicates(p1);
    for (int i = 0; i < t; ++i)
        cout << p1[i] << " ";
    cout << endl;
}

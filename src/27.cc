#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if (len == 0) return 0;
        int l = 0, r = nums.size()-1;
        while (l < len && l <= r) {
            if (nums[l] == val)
                nums[l] = nums[r--];
            else
                l++;
        }
        return l;
    }
};

int main()  {
    Solution s;
    vector<int> p{3};
    vector<int> p1{0,1,2,2,3,0,4,2};

    int ret = s.removeElement(p, 3);
    for (int i = 0; i < ret; ++i) 
        cout << p[i] << " ";
    cout << endl;

    ret = s.removeElement(p1, 0);
    for (int i = 0; i < ret; ++i) 
        cout << p1[i] << " ";
    cout << endl;
}

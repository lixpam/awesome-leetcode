#include <iostream>
#include <vector>
using namespace std;
static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        vector<int> list(len, 1);

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && list[j]+1 > list[i]) {
                    list[i] = list[j]+1;
                }
            }
        }

        int m = list[0];
        for (int i = 1; i < len; ++i) {
            if (m < list[i]) {
                m = list[i];
            }
        }
        return m;
    }
};

int main()
{
    vector<int> arg{10,9,2,5,3,7,101,18};
    Solution s;
    cout << s.lengthOfLIS(arg) << endl;
}

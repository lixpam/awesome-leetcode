#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.length();
        int sum_max = 0;
        int curr_sum = 0;
        int l = 0, r = 0;
        while (l < len && r < len) {
            int diff = s[r] >= t[r] ? s[r] - t[r] : t[r] - s[r];
            if (l == r && maxCost < diff) {
                l++, r++;
                continue;
            }
            if (maxCost >= diff) {
                curr_sum++;
                sum_max = max(curr_sum, sum_max);
                maxCost -= diff;
                r++;
            } else {
                curr_sum--;
                maxCost += (s[l] >= t[l] ? s[l] - t[l] : t[l] - s[l]);
                l++;
            }
        }
        return sum_max;
    }
};

int main()  {
    Solution s;
    string src = "abddddd";
    string dst = "accdddd";
    cout << s.equalSubstring(src, dst, 1) << endl;
}

#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int expandPal(string s, int l, int r) {
        int len = s.size();
        while (l >= 0 && r < len && s[l] == s[r]) {
            --l;
            ++r;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int len = s.size();
        int start = 0, cnt = 0;
        for (int i = 0; i < len; ++i) {
            int l1 = expandPal(s, i, i);
            int l2 = expandPal(s, i, i+1);
            int l = max(l1, l2);
            if (l > cnt) {
                start = i - (l-1)/2;
                cnt = l;
            }
        }
        return s.substr(start, cnt);
    }
};

int main()  {
    Solution s;
    string str = "babad";
    cout << s.longestPalindrome(str) << endl;
}

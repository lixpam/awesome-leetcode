#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <unordered_set>
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == 0) return num;
        if (k >= num.size()) return "0";

        string ret(num.size()-k, '0');

        stack<char> s;
        int i = 0, len = num.size();
        for (; i < len; ++i) {
            while (!s.empty() && k > 0 && num[i] < s.top()) {
                s.pop();
                k--;
            }
            s.push(num[i]);

            if (k == 0) break;
        }

        if (k > 0) {
            while (k--) {
                s.pop();
            }
        } else {
            while (++i < len) {
                s.push(num[i]);
            }
        }

        int _pos = ret.size()-1;
        while (!s.empty()) {
            ret[_pos--] = s.top();
            s.pop();
        }

        int retlen = ret.size();
        if (ret[0] == '0') {
            i = 1;
            while (i < retlen-1 && ret[i] == '0') i++;
            if (i >= retlen) return "0"; 
            return ret.substr(i, retlen-i);
        }
        return ret;
    }
};

int main()  {
    Solution s;
    //cout << s.removeKdigits("1432219", 7) << endl;
    cout << s.removeKdigits("10200", 2) << endl;
}

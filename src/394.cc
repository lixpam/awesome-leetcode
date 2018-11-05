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
    string output(stack<string>& s) {
        if (s.empty()) return "";

        string _t = s.top();
        s.pop();

        return output(s) + _t;
    }
    string decodeString(string s) {
        stack<int> nums;
        stack<string> bstr;

        string ret;
        int len = s.size();
        int start = 0;
        while (start < len) {
            if (s[start] == '[') {
                bstr.push("[");
                start++;
            } else if (s[start] >= '0' && s[start] <= '9') {
                nums.push(eltNum(s, start));
            } else if (isalpha(s[start])) {
                bstr.push(eltStr(s, start));
            } else if (s[start] == ']') {
                string _tmp = bstr.top();
                bstr.pop();
                while (bstr.top() != "[") {
                    _tmp = bstr.top() + _tmp;
                    bstr.pop();
                }
                bstr.pop();

                int rep = nums.top();
                nums.pop();

                string snip;
                for (int i = 0; i < rep; ++i) {
                    snip += _tmp;
                }
                bstr.push(snip);
                start++;
            }
        }
        return output(bstr);
    }
private:
    int eltNum(string& s, int &start) {
        int num = 0;
        while(s[start] >= '0' && s[start] <= '9') {
            num = num*10 + s[start++]-'0';
        }
        return num;
    }
    string eltStr(string &s, int &start) {
        string ret;
        while (isalpha(s[start])) {
            ret += s[start++];
        }
        return ret;
    }
};

int main()  {
    Solution s;
    cout << s.decodeString("3[a]2[bc]") << endl;
    cout << s.decodeString("3[a2[c]]") << endl;
    cout << s.decodeString("2[abc]3[cd]ef") << endl;
}

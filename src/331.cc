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
    bool isValidSerialization(string s) {
        int len = s.size();
        int col = count_if(s.begin(), s.end(), [](const char &c){return c==',';});
        if (col % 2 != 0) return false;

        stack<string> sk;
        int start = 0;
        while (start < len) {
            if (isdigit(s[start]) || s[start] == '-') {
                eltNum(s,start);
                sk.push("0");
            } else if (s[start] == '#') {
                while (!sk.empty() && sk.top() == "#") {
                    sk.pop();
                    if (sk.empty() || sk.top() != "0") return false;
                    sk.pop();
                }
                sk.push("#");
                start++;
            } else {
                start++;
            }
        }

        return sk.size() == 1 && sk.top() == "#";
    }

private:
    string eltNum(string &s, int &start) {
        bool neg = false; 
        if (s[start] == '-') {
            neg = true;
            start++;
        }
        int num = 0;
        while (start < s.size() && isdigit(s[start])) {
            num = num*10 + s[start++]-'0';
        }
        if (neg) {
            num = 0-num;
        } 
        return to_string(num);
    }
};

int main()  {
    Solution s;
    cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << s.isValidSerialization("1,#,#,#") << endl;
    cout << s.isValidSerialization("9,#,#,1") << endl;
    cout << s.isValidSerialization("#") << endl;
}

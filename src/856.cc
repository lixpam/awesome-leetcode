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
    int scoreOfParentheses(string s) {
        int score = 0;

        stack<string> sk;
        for (auto &c : s) {
            if (c == '(') {
                sk.push("(");
            } else {
                int num = 0;
                if (sk.top() != "(") {
                    while (sk.top() != "(") {
                        num += stoi(sk.top());
                        sk.pop();
                    }
                    sk.pop();
                    sk.push(to_string(num*2));
                } else {
                    sk.pop();
                    sk.push("1");
                }
            }
        }

        while (!sk.empty()) {
            score += stoi(sk.top());
            sk.pop();
        }
        return score;
    }
};

int main()  {
    Solution s;
    cout << s.scoreOfParentheses("()") << endl;
    cout << s.scoreOfParentheses("(()(()))") << endl;
    cout << s.scoreOfParentheses("((())(()))") << endl;
}

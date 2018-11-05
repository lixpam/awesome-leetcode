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
    int evalRPN(vector<string>& tokens) {
        stack<int> sk;
        for (auto &it : tokens) {
            if (isdigit(it[0]) || it.size() > 1) {
                sk.push(stoi(it));
            } else {
                int n2 = sk.top();
                sk.pop();
                int n1 = sk.top();
                sk.pop();
                int num = 0;
                switch (it[0]) {
                    case '*':
                        num = n1 * n2;
                        break;
                    case '/':
                        {
                            num = abs(n1)/abs(n2);
                            if ((n1 < 0 && n2 > 0) || (n1 >0 && n2 < 0)) {
                                num = 0-num;
                            }
                        }
                        break;
                    case '+':
                        num = n1 + n2;
                        break;
                    case '-':
                        num = n1 - n2;
                        break;
                }

                sk.push(num);
            }
        }
        return sk.top();
    }
};

int main()  {
    Solution s;
}

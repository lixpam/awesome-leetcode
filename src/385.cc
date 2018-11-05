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

class NestedInteger {
public:
    NestedInteger() {}

    NestedInteger(int value) {
        single_integer = true;
        val = value;
    }

    bool isInteger() const {
        return single_integer;
    }
    int getInteger() const {
        return val;
    }
    void setInteger(int value) {
        single_integer = true;
        val = value;
    }

    // set nestedinteger to list
    void add(const NestedInteger &ni) {
        single_integer =  false;
        _ni.push_back(ni);
    }
    const vector<NestedInteger> &getList() const {
        return _ni;
    }

    void print() {
        if (single_integer) {
            cout << val << " ";
        } else {
            cout << "[";
            for (auto &it : _ni) {
                it.print();
            }
            cout << "]";
        }
    }

private:
    bool single_integer;
    int val;
    vector<NestedInteger> _ni;
};

class Solution {
    struct Token {
        bool isbrace;
        NestedInteger *ni;
        Token(bool isbrace, NestedInteger *ni):isbrace(isbrace),ni(ni){}
    };
public:
    NestedInteger deserialize(string s) {
        stack<Token> sk;
        stack<NestedInteger*> _tmp;
        int len = s.size();
        int start = 0;
        while (start < len) {
            if (s[start] == '[') {
                sk.push({true, NULL});
                start++;
            } else if (s[start] == '-' || (s[start] >= '0' && s[start] <= '9')) {
                int num = eltNum(s, start);
                sk.push({false, new NestedInteger(num)});
            } else if (s[start] == ']') {
                NestedInteger *nit = new NestedInteger;
                while (!sk.empty()) {
                    Token &t = sk.top();
                    sk.pop();
                    if (t.isbrace) break;
                    _tmp.push(t.ni);
                }
                while (!_tmp.empty()) {
                    nit->add(*_tmp.top());
                    _tmp.pop();
                }
                sk.push({false, nit});
                start++;
            } else {
                start++;
            }
        }

        return *sk.top().ni;
    }
private:
    int eltNum(string &s, int &start) {
        int num = 0;
        bool neg = false;
        if (s[start] == '-') {
            neg = true;
            start++;
        }
        while (s[start] >= '0' && s[start] <= '9') {
            num = num*10 + s[start++]-'0';
        }

        return neg ? 0-num : num;
    }
};

int main()  {
    Solution s;
    //NestedInteger ni = s.deserialize("324");
    NestedInteger ni = s.deserialize("[123,[456,[789]]]");
    //NestedInteger ni = s.deserialize("-3");
    ni.print();

}

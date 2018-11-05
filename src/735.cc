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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> sk;
        for (auto &it : asteroids) {
            if (it < 0) {
                int num = it;
                bool coll = false;
                while (num < 0 && !sk.empty() && sk.top() > 0) {
                    int _t = sk.top();
                    sk.pop();
                    if (_t > abs(num)) {
                        num = _t;
                    } else if (_t == abs(num)) {
                        coll = true;
                        break;
                    }
                }
                if (!coll) {
                    sk.push(num);
                }
            } else {
                sk.push(it);
            }
        }

        int len = sk.size();
        vector<int> ret(len, 0);
        while (!sk.empty()) {
            ret[--len] = sk.top();
            sk.pop();
        }
        return ret;
    }
};

int main()  {
    Solution s;
    //vector<int> p{5,10,-5};
    //vector<int> p{8,-8};
    vector<int> p{-2,-1,1,2};
    vector<int> ret = s.asteroidCollision(p);
    for (auto &it : ret) {
         cout << it << " ";
    }
    cout << endl;
}

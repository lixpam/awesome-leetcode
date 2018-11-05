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
    int sumSubarrayMins(vector<int>& a) {
        const int _max = 1000000007;
        int len = a.size();
        int num = 0, acu = 0;
        stack<pair<int, int>> sk;
        for (int i = 0; i < len; ++i) {
            int cnt = 1;
            while (!sk.empty() && sk.top().first >= a[i]) {
                pair<int, int> &_t = sk.top();
                sk.pop();
                acu -= _t.first * _t.second;
                cnt += _t.second;
            }
            sk.push({a[i], cnt});
            acu += a[i] * cnt;
            num += acu;
            num %= _max;
        }
        return num;
    }
};

int main() {
    Solution s;
    vector<int> p;
    for (int i = 0; i < 30000; ++i) {
        p.push_back(i);
    }
    cout << s.sumSubarrayMins(p) << endl;
}

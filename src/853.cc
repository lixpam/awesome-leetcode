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
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> _tmp;
        for (int i = 0; i < position.size(); ++i) {
            _tmp.push_back({position[i], speed[i]});
        }
        sort(_tmp.begin(), _tmp.end(), [](const pair<int,int> &lhs, const pair<int, int> &rhs){return lhs.first < rhs.first;});
        stack<double> sk;
        for (auto &it : _tmp) {
            double _time = (target - it.first)*1.0/it.second;
            sk.push(_time);
        }

        int num = 0;
        while (!sk.empty()) {
            double _curr = sk.top();
            sk.pop();
            while (!sk.empty() && sk.top() <= _curr) {
                sk.pop();
            }
            num++;
        }
        return num;
    }
};

int main()  {
    Solution s;
    vector<int> pos{10,8,0,5,3};
    vector<int> speed{2,4,1,1,3};
    cout << s.carFleet(12, pos, speed) << endl;
}

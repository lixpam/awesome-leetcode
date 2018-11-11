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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<pair<int, int>> mt;
        for (auto &it : intervals) {
            mt.push_back({it.start, 1});
            mt.push_back({it.end, -1});
        }
        sort(mt.begin(), mt.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs){
            if (lhs.first != rhs.first) {
                return lhs.first < rhs.first;
            } else {
                return lhs.second > rhs.second;
            }
        });

        vector<Interval> ret;
        int cnt = 0;
        int start;
        for (auto &it : mt) {
            if (cnt == 0) {
                start = it.first;
            }
            cnt += it.second;
            if (cnt == 0) {
                ret.push_back({start, it.first});
            }
        }
        return ret;
    }
};

int main()  {
    Solution s;

    vector<Interval> p = {
        {1,4},
        {4,5}
    };
    vector<Interval> ret = s.merge(p);
    for (auto &it : ret) {
        cout << it.start << " " << it.end<< endl;
    }
}

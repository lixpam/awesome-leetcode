#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> topKFreq(vector<int>& nums, int k) {
        if (k <= 0) return vector<int>{};

        unordered_map<int,int> tmp;
        for (auto &iter : nums) {
            tmp[iter]++;
        }
        vector<pair<int,int>> list;
        for (auto &iter : tmp) {
            list.emplace_back(iter.first, iter.second);
        }

        auto cmp = [](const pair<int,int>& lh, const pair<int,int>& rh){ 
            if (lh.second != rh.second)
                return lh.second < rh.second;
            else
                return lh.first > rh.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        for (auto &iter : list) {
            if (k > 0) {
                k--;
                pq.push(iter);
            } else {
                if (pq.top().second < iter.second) {
                    pq.pop();
                    pq.push(move(iter));
                }
            }
        }

        vector<int> ret;
        while (!pq.empty()) {
            ret.push_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};

int main()  {
    Solution s;
    vector<int> nums{1,1,1,2,3,2};
    vector<int> ret = s.topKFreq(nums, 2);
    prints(ret);
}

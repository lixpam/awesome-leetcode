#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> tmp;
        for (auto &iter : barcodes) {
            tmp[iter]++;
        }

        priority_queue<pair<int,int>> pq;
        for (auto &iter : tmp) {
            pq.emplace(iter.second, iter.first);
        }

        vector<int> ret(barcodes.size());
        int i = 0;
        while (pq.size() > 1) {
            auto t1 = pq.top();
            pq.pop();
            auto t2 = pq.top();
            pq.pop();
            ret[i++] = t1.second;
            ret[i++] = t2.second;
            if (--t1.first > 0) pq.emplace(t1);
            if (--t2.first > 0) pq.emplace(t2);
        }
        if (!pq.empty()) ret[i] = pq.top().second;
        return ret;
    }
};

int main()  {
    Solution s;
    vector<int> nums{2,2,9,9,9,9,10,10,10,9};
    //vector<int> nums{2,1,1};
    auto ret = s.rearrangeBarcodes(nums);
    prints(ret);
}

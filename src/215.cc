#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &iter : nums) {
            if (k > 0) {
                pq.push(iter);
                k--;
                continue;
            }

            if (pq.empty())
                pq.push(iter);
            else if (iter > pq.top()) {
                pq.pop();
                pq.push(iter);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};

int main()  {
    Solution s;
    vector<int> nums{};
    cout << s.findKthLargest(nums, 4) << endl;
}

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int len = nums.size();
        vector<int> nodes(len, 0);
        vector<int> dist(len, 0);
        nodes[0] = 1;
        dist[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            nodes[i] = nodes[i-1]+1;
            dist[i] = dist[i-1] + nums[i];
            int j = i+1-nodes[i];
            while (j <= i) {
                if (dist[i]-nums[j] >= s) {
                    dist[i] -= nums[j];
                    nodes[i]--;
                    j++;
                } else {
                    break;
                }
            }
        }

        int m = len+1;
        for (int i = 0; i < len; ++i) {
            if (dist[i] >= s && nodes[i] < m) {
                m = nodes[i];
            }
        }

        return m == (len+1) ? 0 : m;
    }
};

int main()
{
    vector<int> arg{1,2,3,4,5};
    Solution s;
    cout << s.minSubArrayLen(15,arg) << endl;
}

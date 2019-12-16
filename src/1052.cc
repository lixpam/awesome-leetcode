#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sum_max = 0;
        int len = grumpy.size();
        for (int k = 0; k < len; ++k) {
            if (grumpy[k] == 0)
                sum_max += customers[k];
        }
        int curr_sum = sum_max;
        for (int i = 0; i < len; ++i) {
            if (i < X) {
                if (grumpy[i] == 1) {
                    curr_sum += customers[i];
                    sum_max = curr_sum;
                }
            } else {
                if (grumpy[i-X] == 1)
                    curr_sum -= customers[i-X];
                if (grumpy[i] == 1)
                    curr_sum += customers[i];
                sum_max = max(curr_sum, sum_max);
            }
        }
        return sum_max;
    }
};

int main()  {
    Solution s;
    vector<int> customers{1,0,1,2,1,1,7,5};
    vector<int> grumpy{0,1,0,1,0,1,0,1};
    cout << s.maxSatisfied(customers, grumpy, 3) << endl;
}

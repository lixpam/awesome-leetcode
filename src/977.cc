#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result(A.size());
        int l = 0, r = A.size()-1;
        if (r < 0) return result;
        int curr = r;

        int l2 = pow(A[l], 2);
        int r2 = pow(A[r], 2);
        while (l <= r) {
            if (l2 >= r2) {
                result[curr--] = l2;
                l++;
                if (l <= r)
                    l2 = pow(A[l], 2);
            } else {
                result[curr--] = r2;
                r--;
                r2 = pow(A[r], 2);
            }
        }
        return result;
    }
};

int main()  {
    Solution s;
    vector<int> p{-4, -1, 0, 3, 10};
    vector<int> p2{-7,-3,2,3,11};
    vector<int> p3{1,2,3,4};
    vector<int> p4{1};

    auto ret = s.sortedSquares(p);
    prints(ret);

    auto ret1 = s.sortedSquares(p2);
    prints(ret1);

    auto ret2 = s.sortedSquares(p3);
    prints(ret2);

    auto ret3 = s.sortedSquares(p4);
    prints(ret3);
}


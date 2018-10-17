#include <iostream>
#include <vector>
using namespace std;

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        for (auto &row : matrix) {
            if (target < row[0]) break;
            if (target > row[n-1]) continue;

            int lo = 0, hi = n-1;
            while (lo < hi) {
                int mid = (lo+hi)/2;
                if (row[mid] == target) return true;

                if (row[mid] < target) {
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }
            if (lo == hi && row[lo] == target) return true;
        }

        return false;
    }
};

int main()
{
    vector<vector<int>> arg{
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    Solution s;
    cout << s.searchMatrix(arg, 20) << endl;
}

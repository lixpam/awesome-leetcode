#include <iostream>
#include <vector>

using namespace std;

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

/* O(N)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int len = A.size();
        for (int i = 0; i < len-1; ++i) {
            if (A[i] > A[i+1]) {
                return i;
            }   
        }
        return len-1;
    }
};
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int lo = 0, hi = A.size()-1;
        while (lo < hi) {
            int mid = lo + (hi-lo)/2;
            if (A[mid] < A[mid+1]) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};

int main()
{
    Solution s;
    vector<int> args{0,1,2,3,1,0};
    cout << s.peakIndexInMountainArray(args) << endl;
}

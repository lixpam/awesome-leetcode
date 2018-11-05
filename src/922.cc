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
    vector<int> sortArrayByParityII(vector<int>& A) {
        int len = A.size();
        int odd = 0, even = 1;
        while (odd < len) {
            if (A[odd]%2 == 1) {
                while (A[even]%2 != 0) {
                    even += 2;
                } 
                swap(A[odd], A[even]);
            }
            odd += 2;
        }
        return A;
    }
};

int main()
{
    vector<int> arg{2,4,1,1,1,3,4,3,2,0};

    Solution s;
    vector<int> ret = s.sortArrayByParityII(arg);
    for (auto &i : ret) {
        cout << i << " ";
    }
    cout << endl;
}

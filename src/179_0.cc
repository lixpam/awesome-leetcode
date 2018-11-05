#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> _t;
        for (auto &i : nums) {
            _t.push_back(to_string(i));
        }
        sort(_t.begin(), _t.end(), [](const string &lhs, const string &rhs)->bool{
                return (lhs + rhs) > (rhs + lhs);
        });

        if (_t[0] == "0") return "0";

        string ret;
        for (auto &i : _t) {
            ret += i;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> s1{0, 9, 8, 7, 6, 5, 4, 3,2,1};
    cout << s.largestNumber(s1) << endl;
}

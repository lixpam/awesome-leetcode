#include <iostream>
#include <unordered_map>

using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    public:
        int numJewelsInStones(string J, string S) {
            int cnt = 0;
            unordered_map<char, int> sh;
            for (auto &c : S) {
                sh[c]++;
            }
            for (auto &c : J) {
                cnt += sh[c];
            }
            return cnt;
        }

};

int main()
{
    Solution s;
    cout << s.numJewelsInStones("aA", "aAASSSS") << endl;
    return 0;
}

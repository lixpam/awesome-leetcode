#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rl = matrix.size();
        if (rl == 0) return;
        int cl = matrix[0].size();

        unordered_set<int> rows;
        unordered_set<int> cols;

        for (int i = 0; i < rl; ++i) {
            for (int j = 0; j < cl; ++j) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (auto r : rows) {
            for (int i = 0; i < cl; ++i) {
                matrix[r][i] = 0;
            }
        }
        for (auto c : cols) {
            for (int i = 0; i < rl; ++i) {
                matrix[i][c] = 0;
            }
        }
    }
};

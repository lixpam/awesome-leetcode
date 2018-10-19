#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

const static int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return matrix;

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> mdist(m, vector<int>(n, INT_MAX-10000));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    mdist[i][j] = 0;
                } else {
                    if (i > 0) {
                        mdist[i][j] = min(mdist[i][j], mdist[i-1][j]+1);
                    }
                    if (j > 0) {
                        mdist[i][j] = min(mdist[i][j], mdist[i][j-1]+1);
                    }
                }
            }
        }

        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if (matrix[i][j] == 0) {
                    mdist[i][j] = 0;
                } else {
                    if (i < m-1) {
                        mdist[i][j] = min(mdist[i][j], mdist[i+1][j]+1);
                    }
                    if (j < n-1) {
                        mdist[i][j] = min(mdist[i][j], mdist[i][j+1]+1);
                    }
                }
            }
        }

        return mdist;
    }
};

int main()
{
    vector<vector<int>> arg1{
{1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
{0, 1, 1, 0, 1, 0, 1, 0, 1, 1}, 
{0, 0, 1, 0, 1, 0, 0, 1, 0, 0}, 
{1, 0, 1, 0, 1, 1, 1, 1, 1, 1}, 
{0, 1, 0, 1, 1, 0, 0, 0, 0, 1}, 
{0, 0, 1, 0, 1, 1, 1, 0, 1, 0}, 
{0, 1, 0, 1, 0, 1, 0, 0, 1, 1}, 
{1, 0, 0, 0, 1, 1, 1, 1, 0, 1}, 
{1, 1, 1, 1, 1, 1, 1, 0, 1, 0}, 
{1, 1, 1, 1, 0, 1, 0, 0, 1, 1}
    };

    vector<vector<int>> arg2{
        {0,1,1},
        {0,1,1},
        {1,1,1}
    };

    Solution s;
    vector<vector<int>> ret1 = s.updateMatrix(arg1);
    vector<vector<int>> ret2 = s.updateMatrix(arg2);

    for (auto &row : ret1) {
        for (auto &col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (auto &row : ret2) {
        for (auto &col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;
}

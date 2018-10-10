#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool traverse(vector<vector<char>>& board, int m, int n, const char *result, int len) {
        if (len <= 0) return true;
        if (m < 0 || m >= board.size()) return false;
        if (n < 0 || n >= board[0].size()) return false;
        int row = board.size();
        if (board[m][n] != result[0] || status[m][n]) return false;

        status[m][n] = true;
        if (traverse(board, m+1, n, result+1, len-1)
            || traverse(board, m-1, n, result+1, len-1)
            || traverse(board, m, n+1, result+1, len-1)
            || traverse(board, m, n-1, result+1, len-1)) return true;
        status[m][n] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<int, vector<pair<int,int>>> cache;
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                vector<pair<int,int>> &c = cache[board[i][j]];
                c.push_back(pair<int,int>(i, j));
            }
        }

        status.clear();
        for (int i = 0; i < row; ++i) {
            status.push_back(vector<bool>(col, false));
        }

        for (auto &it : cache[word[0]]) {
            for (int i = 0; i < row; ++i) {
                status[i].assign(col, false);
            }
            bool ret = traverse(board, it.first, it.second, word.c_str(), word.size());
            if (ret) return ret;
        }
        return false;
    }
private:
    vector<vector<bool>> status;
};

int main()
{
    vector<vector<char>> arg = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    Solution s;
    cout << "ABCCED : " << s.exist(arg, "ABCCED") << endl;
    cout << "SEE: " << s.exist(arg, "SEE") << endl;
    cout << "ABCB: " << s.exist(arg, "ABCB") << endl;
    cout << "FCS: " << s.exist(arg, "FCS") << endl;
    cout << "FCSE: " << s.exist(arg, "FCSE") << endl;
    cout << "FCSEE: " << s.exist(arg, "FCSEE") << endl;
    cout << "FCSEEC: " << s.exist(arg, "FCSEEC") << endl;
    cout << "FCSED: " << s.exist(arg, "FCSED") << endl;
}

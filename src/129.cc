#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* root, int curr) {
        if (!root) return;
        curr = curr*10 + root->val;
        if (!root->left && !root->right) {
            sum += curr;
            return;
        }
        if (root->left) dfs(root->left, curr);
        if (root->right) dfs(root->right, curr);
    }
    int sumNumbers(TreeNode* root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }
private:
    int sum = 0;
};

int main()  {
    Solution s;
    TreeNode *root = new TreeNode(4);
    root->right = new TreeNode(0);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    cout << s.sumNumbers(root) << endl;
}

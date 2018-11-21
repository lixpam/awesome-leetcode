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
    bool isValidChild(TreeNode *root, long _min, long _max) {
        if (!root) return true;
        if (root->val <= _min || root->val >= _max) return false;

        if (root->left && !isValidChild(root->left, _min, root->val)) return false;
        if (root->right && !isValidChild(root->right, root->val, _max)) return false;

        return true;
    }
    bool isValidBST(TreeNode* root) {
        return isValidChild(root, LONG_MIN, LONG_MAX);
    }
};

int main()  {
    Solution s;

    TreeNode *root = new TreeNode(2147483647);

    cout << s.isValidBST(root) << endl;
}


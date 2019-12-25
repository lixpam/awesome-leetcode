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
    TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if (ps > pe) return nullptr;
        TreeNode *root = new TreeNode(preorder[ps]);

        int index = is;
        for (int i = is; i <= ie; ++i)
            if (inorder[i] == preorder[ps]) {
                index = i;
                break;
            }

        root->left = build(preorder, ps+1, ps+index-is, inorder, is, index-1);
        root->right = build(preorder, ps+index-is+1, pe, inorder, index+1, ie);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};

int main()  {
    Solution s;
    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};
    TreeNode *root = s.buildTree(preorder, inorder);
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size-->0) {
            TreeNode *tmp = q.front();
            q.pop();
            cout << tmp->val << " ";
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        cout << endl;
    }
}

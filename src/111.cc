#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (root->left && root->right)
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        else if (root->left)
            return minDepth(root->left) + 1;
        else if (root->right) 
            return minDepth(root->right) + 1;
        else
            return 1;
    }
};

int main()  {
    Solution s;
}

#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main()  {
    Solution s;
}

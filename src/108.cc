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
    TreeNode* createBST(vector<int>& nums, int s, int e) {
        if (s > e) return nullptr;

        if (s == e) {
            return new TreeNode(nums[s]);
        }

        int mid = s + (e-s)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = createBST(nums, s, mid-1);
        root->right = createBST(nums, mid+1, e);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return createBST(nums, 0, nums.size()-1);
    }
};

int main()  {
    Solution s;
    vector<int> nums{-10,-8,1,2,3,4,5,6};
    TreeNode *root = s.sortedArrayToBST(nums);
    
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size-- > 0) {
            TreeNode *tmp = q.front();
            q.pop();
            cout << tmp->val << " ";
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
        cout << endl;
    }
}

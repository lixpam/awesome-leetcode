#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    TreeNode* insertbst(TreeNode *root, int val) {
        if (!root) {
            return new TreeNode(val);
        }

        if (val < root->val) {
            root->left = insertbst(root->left, val);
        } else {
            root->right = insertbst(root->right, val);
        }
        return root;
    }

    void insertByList(vector<int>& nums, TreeNode *&root, int start, int end) {
        if (start > end) return ;
        if (start == end) {
            root = insertbst(root, nums[start]);
            return;
        }

        int mid = (start+end)/2;
        root = insertbst(root, nums[mid]);
        if (mid != start) {
            insertByList(nums, root, start, mid-1);
        }
        insertByList(nums, root, mid+1, end);
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;

        int lo = 0, hi = 0;
        vector<int> arg;
        while (head) {
            arg.push_back(head->val);
            head = head->next;
            hi++;
        }

        TreeNode *root = NULL;
        insertByList(arg, root, 0, hi-1);
        return root;
    }
};

void levelTraverse(TreeNode *root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        cout << cur->val << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    cout << endl;
}

int main()
{
    ListNode *root = new ListNode(-10);
    root->next = new ListNode(-3);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(5);
    root->next->next->next->next = new ListNode(9);

    Solution s;
    TreeNode *node = s.sortedListToBST(root);

    levelTraverse(node);
}


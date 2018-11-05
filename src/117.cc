#include <iostream>
#include <queue>
using namespace std;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *now, *head, *tail;

        now = root;
        head = tail = NULL;
        while (now) {
            if (now->left) {
                if (tail)
                    tail = tail->next = now->left;
                else
                    head = tail = now->left;
            }
            if (now->right) {
                if (tail)
                    tail = tail->next = now->right;
                else
                    head = tail = now->right;
            }
            if (!(now = now->next)) {
                now = head;
                head = tail = NULL;
            }
        }
    }
    /*
    void connect(TreeLinkNode *root) {
        if (!root) return ;

        queue<TreeLinkNode*> m;
        m.push(root);
        m.push(NULL);

        while (!m.empty()) {
            TreeLinkNode *tmp = m.front();
            m.pop();
            if (tmp->left) m.push(tmp->left);
            if (tmp->right) m.push(tmp->right);
            while (m.front() != NULL) {
                tmp->next = m.front();
                tmp = m.front();
                m.pop();

                if (tmp->left) m.push(tmp->left);
                if (tmp->right) m.push(tmp->right);
            }
            tmp->next = NULL;
            m.pop();
            if (!m.empty()) {
                m.push(NULL);
            }
        }
    }
    */
};

void levelTraverse(TreeLinkNode *root) {
    queue<TreeLinkNode*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        TreeLinkNode *tmp = q.front();
        q.pop();
        while (tmp) {
            cout << tmp->val << " ";
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
            tmp = tmp->next;
        }
        cout << "NULL" << endl;

        while (q.front() != NULL) {
            q.pop();
        }
        q.pop();

        if (!q.empty()) {
            q.push(NULL);
        }
    }
}

int main()
{
    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right= new TreeLinkNode(3);

    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);

    root->right->right = new TreeLinkNode(7);

    Solution s;
    s.connect(root);
    levelTraverse(root);
}

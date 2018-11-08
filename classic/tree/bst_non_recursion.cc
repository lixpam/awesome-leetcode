#include <iostream>
#include <queue>
#include <stack>

// 二叉查找树 ——非递归版本

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int val):val(val), left(NULL),right(NULL){}
};

Node* insertNode(Node *root, int val) {
    if (!root) {
        return new Node(val);
    }

    Node *nnode = new Node(val);
    Node *parent = root;
    Node *lhs = parent->left, *rhs = parent->right;
    while (parent) {
        if (val < parent->val) {
            if (!lhs) {
                parent->left = nnode;
                return root;
            }
            parent = lhs;
            lhs = parent->left;
            rhs = parent->right;
        } else {
            if (!rhs) {
                parent->right = nnode;
                return root;
            }
            parent = rhs;
            lhs = parent->left;
            rhs = parent->right;
        }
    }

    return root;
}

bool deleteNode(Node*& root, int val) {
    if (!root) return false;
    if (!root->left && !root->right) {
        if (root->val != val) return false;

        delete root;
        root = NULL;
        return true;
    }

    if (val < root->val) {
        return deleteNode(root->left, val);
    } else if (val > root->val) {
        return deleteNode(root->right, val);
    } else {
        if (!root->left || !root->right) {
            Node *del = root;
            root = root->left == NULL ? root->right : root->left;
            delete del;
            del = NULL; 
            return true;
        } else {
            Node *swp = root->right;
            while (swp->left) swp = swp->left;
            swap(root->val, swp->val);
            return deleteNode(root->right, val);
        }
    }
    return false;
}

Node* searchNode(Node *root, int val) {
    if (!root) return NULL;

    Node *curr = root;
    while (curr) {
        if (curr->val == val)  {
            return curr;
        } else if (val < curr->val) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return curr;
}

// 前序遍历
// 非递归，利用栈的特性：先进后出
// 先将父节点压栈，当栈不为空时，取出节点输出，并将右节点和左节点依次压入栈
void prevTraverse(Node *root) {
    if (!root) return;

    stack<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *curr = q.top();
        q.pop();
        cout << curr->val << " ";
        if (curr->right) q.push(curr->right);
        if (curr->left) q.push(curr->left);
    }
}

// 中序遍历
// 非递归版本
// 从根节点p开始
// 1. 如果p有左节点，将P入栈，将p的左节点设置当前节点，重复此步骤
// 2. 如果P的左节点为空，输入P节点，并将右节点设置成当前节点，看是否为空
// 3. 如果不为空，重复1，2
// 4. 如果为空，弹出栈顶，并输出，并将栈的右节点设置成当前节点，看是否为空，重复3，4
// 5. 直到当前节点p为null且栈为空，结束遍历

void inTraverse(Node *root) {
    if (!root) return;

    stack<Node*> q;
    Node *p = root;
    while (p || !q.empty()) {
        if (p->left) {
            q.push(p);
            p = p->left;
        } else {
            cout << p->val << " ";
            p = p->right;
            while (!p && !q.empty()) {
                p = q.top();
                q.pop();
                cout << p->val << " ";
                p = p->right;
            }
        }
    }
}

// 后序遍历
// 1. 将节点入栈
// 2. 若P不存在左右孩子，或者P存在左右孩子，但左右孩子已经被输出，则直接输入P，将其出栈，并将此时P标记为上个输出的节点，在将此时栈顶设置为当前节点
// 3. 如果不满足2，将p右孩子和左孩子依次入栈，并将当前节点重新设置为栈顶节点，重复2
// 4. 栈空，结束
void postTraverse(Node *root) {
    if (!root) return;

    Node *curr = NULL, *prev = NULL;

    stack<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *curr = q.top();
        if ((curr->left == NULL && curr->right == NULL)
            || (prev != NULL && (curr->left == prev || curr->right == prev)))
        {
            cout << curr->val << " ";
            q.pop();
            prev = curr;
        } else {
            if (curr->right) {
                q.push(curr->right);
            }
            if (curr->left) {
                q.push(curr->left);
            }
        }
    }
}

void levelTraverse(Node *root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *cur = q.front();
        q.pop();
        cout << cur->val << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

int main()
{
    int a[] = {15,5,3,12,10,13,6,7,16,20,18,23};
    Node *root = NULL;
    for (auto &i : a) {
        root = insertNode(root, i);
    }

    prevTraverse(root);
    cout << endl;
    inTraverse(root);
    cout << endl;
    postTraverse(root);
    cout << endl;
    return 0;
}

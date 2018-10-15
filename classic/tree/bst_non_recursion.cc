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

void inTraverse(Node *root) {
    if (!root) return;

    stack<Node*> q;
    if (root->right) q.push(root->right);
    q.push(root);
    if (root->left) q.push(root->left);

    while (!q.empty()) {
        Node * curr = q.top();
    }

    inTraverse(root->left);
    cout << root->val << " ";
    inTraverse(root->right);
}

void postTraverse(Node *root) {
    if (!root) return;

    postTraverse(root->left);
    postTraverse(root->right);
    cout << root->val << " ";
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
    levelTraverse(root);
    cout << endl;

    //deleteNode(root, 5);
    //levelTraverse(root);
    //cout << endl;
}

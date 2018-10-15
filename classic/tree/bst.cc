#include <iostream>
#include <queue>

// 二叉查找树 ——递归版本

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

    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
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
    if (root->val == val) return root;

    if (val < root->val) {
        return searchNode(root->left, val);
    } else {
        return searchNode(root->right, val);
    }
}

void prevTraverse(Node *root) {
    if (!root) return;

    cout << root->val << " ";
    prevTraverse(root->left);
    prevTraverse(root->right);
}

void inTraverse(Node *root) {
    if (!root) return;

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
    levelTraverse(root);
    cout << endl;

    deleteNode(root, 5);
    levelTraverse(root);
    cout << endl;
}

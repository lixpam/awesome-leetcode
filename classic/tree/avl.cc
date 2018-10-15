#include <iostream>
#include <queue>
using namespace std;

// AVL二叉平衡树

struct Node {
    int val;
    int hgt;        //以此节点为根的树的高度
    Node *left, *right;
    Node(int val):val(val),left(NULL),right(NULL),hgt(0){}
};

int height(Node *n) {
    if (n) {
        return n->hgt;
    }
    return -1;
}

// rotate left left
void singleRotateLL(Node* &root) {
    Node *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;

    root->hgt = max(height(root->left), height(root->right)) + 1;
    tmp->hgt = max(height(tmp->left), root->hgt) + 1;

    root = tmp;
}

//rotate right right
void singleRotateRR(Node* &root) {
    Node *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;

    root->hgt = max(height(root->left), height(root->right)) + 1;
    tmp->hgt = max(root->hgt, height(tmp->right)) + 1;

    root = tmp;
}

// double rotate left right
void doubleRotateLR(Node* &root) {
    singleRotateRR(root->left);
    singleRotateLL(root);
}

// double rotate right left
void doubleRotateRL(Node* &root) {
    singleRotateLL(root->right);
    singleRotateRR(root);
}

void insertNode(Node* &root, int val) {
    if (!root) {
        root = new Node(val);
        return;
    }

    if (val < root->val) {
        insertNode(root->left, val);
        if ((height(root->left) - height(root->right)) == 2) {
            if (val < root->left->val) {
                // ll
                singleRotateLL(root);
            } else {
                // lr
                doubleRotateLR(root);
            }
        }
    } else {
        insertNode(root->right, val);
        if ((height(root->right) - height(root->left)) == 2) {
            if (val < root->right->val) {
                // rl
                doubleRotateRL(root);
            } else {
                // rr
                singleRotateRR(root);
            }
        }
    }

    root->hgt = max(height(root->left), height(root->right)) + 1;
}

bool deleteNode(Node* &root, int val) {
    if (!root) return false;

    bool exist = false;
    if (val < root->val) {
        exist = deleteNode(root->left, val);
        if (exist && (height(root->right) - height(root->left)) == 2) {
            if (root->right->left != NULL && (height(root->right->left) > height(root->right->right))) {
                doubleRotateRL(root);
            } else {
                singleRotateRR(root);
            }
        }
    } else if (val > root->val) {
        exist = deleteNode(root->right, val);
        if (exist && (height(root->left) - height(root->right)) == 2) {
            if (root->left->right != NULL && (height(root->left->right) > height(root->left->left))) {
                doubleRotateLR(root);
            } else {
                singleRotateLL(root);
            }
        }
    } else {
        exist = true;
        if (root->left && root->right) {
            // 有两个子节点
            Node *tmp = root->right;
            while (tmp->left) tmp = tmp->left;    // 类似BST，从右子树找到最小节点代替之
            swap(root->val, tmp->val);
            deleteNode(root->right, tmp->val);
            if ((height(root->left)-height(root->right)) == 2) {
                if (root->left->right && (height(root->left->right) > height(root->left->left))) {
                    //lr
                    doubleRotateLR(root);
                } else {
                    // ll
                    singleRotateLL(root);
                }
            }
        } else {
            // 只有一个子节点或0个
            Node *tmp = root;
            if (tmp->left) {
                root = root->left;
            } else {
                root = root->right;
            }
            delete tmp;
            tmp = NULL;
        }
    }
    if (root) {
        root->hgt = max(height(root->left), height(root->right)) + 1;
    }

    return exist;
}

Node* searchNode(Node *root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;

    if (val < root->val) {
        return searchNode(root->left, val);
    }  else {
        return searchNode(root->right, val);
    }

    return NULL;
}

void levelTraverse(Node *root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node *cur = q.front();
        q.pop();
        cout << cur->val << "(" << cur->hgt << ") ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

int main()
{
    int a[] = {18, 8, 22, 4, 19, 24, 21};
    Node *root = NULL;
    for (auto &i : a) {
        insertNode(root, i);
    }

    levelTraverse(root);
    cout << endl;

    cout << deleteNode(root, 4) << endl;
    levelTraverse(root);
    cout << endl;

    cout << deleteNode(root, 8) << endl;
    levelTraverse(root);
    cout << endl;
}

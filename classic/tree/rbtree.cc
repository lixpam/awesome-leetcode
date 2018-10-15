#include <iostream>
#include <queue>

// 红黑树

using namespace std;

#define RED   1
#define BLACK 2

struct Node {
    unsigned char color;
    int val;
    Node *left, *right, *parent;

    Node(){};
    Node(int val, unsigned char color):val(val), color(color), left(NULL), right(NULL), parent(NULL){};
};

Node* newNode(int val) {
    Node *n = new Node(val, RED);
    return n;
}

void insertRotateFix(Node *root, Node *p) {

}

Node* insertRBTreeNode(Node *root, int val) {
    Node *n = newNode(val);
    if (root == NULL) {
        n->color = BLACK;
        return n;
    }

    Node *p = root;
    while (true) {
        if (p->val > val) {
            if (p->left == NULL) {
                p->left = n;
                n->parent = p;
                break;
            } else {
                p = p->left;
            }
        } else {
            if (p->right == NULL) {
                p->right = n;
                n->parent = p;
                break;
            } else {
                p = p->right;
            }
        }
    }

    insertRotateFix(root, n);

    return root;
}

Node* search(Node *root, int val) {
    if (root == NULL) return NULL;
    
    if (root->val == val) return root;

    return root->val < val ? search(root->right, val) : search(root->left, val);
}

void prevTraverse(Node *root) {
    if (root == NULL) return;
    
    cout << root->val << " ";
    prevTraverse(root->left);
    prevTraverse(root->right);
}

void inTraverse(Node *root) {
    if (root == NULL) return;
    
    inTraverse(root->left);
    cout << root->val << " ";
    inTraverse(root->right);
}

void postTraverse(Node *root) {
    if (root == NULL) return;
    
    postTraverse(root->left);
    postTraverse(root->right);
    cout << root->val << " ";
}

void levelTraverse(Node *root) {
    if (root == NULL) return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        Node *tmp = q.front();
        cout << tmp->val << " ";
        q.pop();
        if (tmp->left) {
            q.push(tmp->left);
        }
        if (tmp->right) {
            q.push(tmp->right);
        }
    }
}

// 左旋，将右子树设为父节点，自己设为右子树的左节点，右子树的左子树设为自己的右子树
Node* leftRotate(Node *root, Node *p) {
    /*没有记录parent时，可用此代码
    if (root == NULL || p == NULL) return;

    Node *pr = p->right;
    if (pr == NULL) return;

    swap(p->val, pr->val);

    p->right = pr->right;
    pr->right = pr->left;
    pr->left = p->left;
    p->left = pr;
    */

    if (root == NULL || p == NULL) return root;

    Node *pr = p->right;
    if (pr == NULL) return root;

    Node *pp = p->parent;

    p->parent = pr;
    p->right = pr->left;
    pr->left = p;
    if (pp) {
        if (p == pp->left) {
            pp->left = pr;
        } else {
            pp->right = pr;
        }
    } else {
        root = pr;
    }
    return root;
}

// 右旋，将左子树设为父节点，自己设为左子树的右节点, 左子树的右子树设置为自己的左子树
Node* rightRotate(Node *root, Node *p) {
    /*没有记录parent时，可用此代码
    if (root == NULL || p == NULL) return;

    Node *pl = p->left;
    if (pl == NULL) return;

    swap(p->val, pl->val);

    p->left = pl->left;
    pl->left = pl->right;
    pl->right = p->right;
    p->right = pl;
    */

    if (root == NULL || p == NULL) return root;

    Node *pl = p->left;
    if (pl == NULL) return root;

    Node *pp = p->parent;
    
    p->parent = pl;
    p->left = pl->right;
    pl->right = p;

    if (pp) {
        if (pp->left == p) {
            pp->left = pl;
        } else {
            pp->right = pl;
        }
    } else {
        root = pl;
    }
    return root;
}

int main()
{
    int size = 6;
    int a[] = {6,2,1,4,3,7};

    Node *root = NULL;
    for (int i = 0; i < size; ++i) {
        root = insertRBTreeNode(root, a[i]);
    }
    cout << endl;

    levelTraverse(root);
    cout << endl;

    Node *p = search(root, 4);
    rightRotate(root, p);
    levelTraverse(root);
    cout << endl;

    return 0;
}

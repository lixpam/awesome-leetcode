#include <iostream>
#include <queue>
using namespace std;

#define RED   0
#define BLACK 1

class RBTree {
private:
    struct Node {
        bool color;
        int val;
        Node *left, *right, *parent;

        Node():val(0),color(RED),left(NULL),right(NULL),parent(NULL){};
        Node(int val):val(val), color(RED), left(NULL), right(NULL), parent(NULL){};
        Node* grandparent() {
            if (!parent) return NULL;
            return parent->parent;
        }

        Node* uncle() {
            Node *grandp = grandparent();
            if (grandp == NULL) return NULL;
            if (grandp->left == parent) {
                return grandp->right;
            } else {
                return grandp->left;
            }
        }

        Node* sibling() {
            if (!parent) return NULL;

            if (parent->left == this) {
                return parent->right;
            } else {
                return parent->left;
            }
        }
    };

    // 左右旋都是将当前节点放置于其父节点位置，父节点位置下降到其左或右子树
    // 右旋
    void rotateRight(Node *n) {
        if (n->parent == NULL) {
            root = n;
            return;
        }

        Node *gp = n->grandparent();        // 祖父
        Node *fa = n->parent;               // 父
        Node *y = n->right; 

        // 将n的右子树挂到原来父节点的左子树，原来父节点变成n的右子树
        fa->left = y;
        if (y) {
            y->parent = fa;
        }
        n->right = fa;
        fa->parent = n;

        if (root == fa) {
            root = n;
        }
        n->parent = gp;

        if (gp) {
            if (gp->left == fa) {
                gp->left = n;
            } else {
                gp->right = n;
            }
        }
    }

    // 左旋
    void rotateLeft(Node *n) {
        if (n->parent == NULL) {
            root = n;
            return;
        }

        Node *gp = n->grandparent();        // 祖父
        Node *fa = n->parent;               // 父
        Node *y = n->left; 

        // 将n的左子树挂到原来父节点的右子树，原来父节点变成n的左子树
        fa->right = y;
        if (y) {
            y->parent = fa;
        }
        n->left = fa;
        fa->parent = n;

        if (root == fa) {
            root = n;
        }
        n->parent = gp;

        if (gp) {
            if (gp->left == fa) {
                gp->left = n;
            } else {
                gp->right = n;
            }
        }
    }

    void insert(Node *p, int val) {
        if (val < p->val) {
            if (p->left != NULL) {
                insert(p->left, val);
            } else {
                Node *t = new Node(val);
                t->parent = p;
                p->left = t;
                insertRotateFix(t);
            }
        } else {
            if (p->right != NULL) {
                insert(p->right, val);
            } else {
                Node *t = new Node(val);
                t->parent = p;
                p->right = t;
                insertRotateFix(t);
            }
        }
    }

    // 插入节点后检车是否平衡，不平衡进入修复
    void insertRotateFix(Node *n) {
        // case1. 新节点是root，改变根颜色为黑
        if (!n->parent) {
            root = n;
            root->color = BLACK;
            return;
        }

        // case2. 父节点是黑色，树任然有效
        if (n->parent->color == BLACK) {
            return;
        }

        // 接下来父节点都是红色，所以一定有祖父节点
        // case3. 叔父节点是红色
        if (n->uncle()->color == RED) {
            n->parent->color = n->uncle()->color = BLACK;
            n->grandparent()->color = RED;
            insertRotateFix(n->grandparent());
        } else {
            if (n->parent->right == n && n->grandparent()->left == n->parent) {
                // case4. 在祖父节点的左子树的右子树
                rotateLeft(n);
                rotateRight(n);
                n->color = BLACK;
                n->left->color = n->right->color = RED;
            } else if (n->parent->left == n && n->grandparent()->right == n->parent) {
                // case4. 和上面case4对称
                rotateRight(n);
                rotateLeft(n);
                n->color = BLACK;
                n->left->color = n->right->color = RED;
            } else if (n->parent->left == n && n->grandparent()->left == n->parent) {
                // case5. 在祖父节点的左子树的左子树上
                n->parent->color = BLACK;
                n->grandparent()->color = RED;
                rotateRight(n->parent);
            } else if (n->parent->right == n && n->grandparent()->right == n->parent) {
                // case5. 和上面case5对称
                n->parent->color = BLACK;
                n->grandparent()->color = RED;
                rotateLeft(n->parent);
            }
        }
    }

    bool delete_child(Node *p, int val) {
        if (!p) return false;

        if (val < p->val) {
            if (!p->left) {
                return false;
            }
            return delete_child(p->left, val);
        } else if (val > p->val) {
            if (!p->right) {
                return false;
            }
            return delete_child(p->right, val);
        } else {
            // 找右子树的最小代替之，并继续递归查找删除，使得最终删除落在值删除有一个子节点的情况下
            // 删除类似BST的删除
            if (!p->right) {
                delete_one_child(p);
                return true;
            }

            Node *smallest = p->right;
            if (smallest->left) smallest = smallest->left;
            swap(p->val, smallest->val);
            delete_one_child(smallest);

            return true;
        }
    }

    void delete_one_child(Node *p) {
        Node *child = p->left == NULL ? p->right : p->left;

        // case1. root
        if (!p->parent && !p->left && !p->right) {
            delete p;
            p = NULL;
            root = p;
            return;
        }

        if (p->parent == NULL) {
            delete p;
            p = NULL;
            child->parent = NULL;
            root = child;
            root->color = BLACK;
            return;
        }

        // 把节点p从树中剔除
        if (p->parent->left == p) {
            p->parent->left = child;
        } else {
            p->parent->right = child;
        }
        child->parent = p->parent;

        // 只有删除黑色节点才有影响
        if (p->color == BLACK) {
            if (child->color == RED) {
                child->color = BLACK;
            } else {
                deleteFix(child);
            }
        }

        delete p;
    }

    void deleteFix(Node *p) {
        // case1. root
        if (p->parent == NULL) {
            p->color = BLACK;
            return;
        }

        // case2. 新节点的兄弟节点是RED, 在其父节点做左/右旋, 把红色兄弟换成新节点的祖父节点，然后重新着色
        if (p->sibling()->color == RED) {
            p->parent->color = RED;
            p->sibling()->color = BLACK;
            if (p->parent->left == p) {
                rotateLeft(p->sibling());
            } else {
                rotateRight(p->sibling());
            }
        }

        // case3. P的父亲、bro和bro的儿子都是黑色的. 重新绘制bro颜色为红
        if (p->parent->color == BLACK && p->sibling()->color == BLACK && p->sibling()->left->color == BLACK && p->sibling()->right->color == BLACK) {
            p->sibling()->color = RED;
            deleteFix(p->parent);
        } else if (p->parent->color == RED && p->sibling()->color == BLACK && p->sibling()->left->color == BLACK && p->sibling()->right->color == BLACK) {
            // case4. P的父亲红色, bro和bro的儿子是黑色的
            p->sibling()->color = RED;
            p->parent->color = BLACK;
        } else {
            // case5. bro黑色，bro的左儿子是红色，右儿子是黑色，我们进行左/右旋转
            if (p->sibling()->color == BLACK) {
                if (p->parent->left == p && p->sibling()->left->color == RED && p->sibling()->right->color == BLACK) {
                    p->sibling()->color = RED;
                    p->sibling()->left->color = BLACK;
                    rotateRight(p->sibling()->left);
                } else if (p->parent->right == p && p->sibling()->left->color == BLACK && p->sibling()->right->color == RED) {
                    p->sibling()->color = RED;
                    p->sibling()->right->color = BLACK;
                    rotateLeft(p->sibling()->right);
                }
            }

            // case6. bro是黑色，bro的右儿子是红色，而P是它父亲的左儿子, 对p兄弟做左旋，相对称的做右旋
            p->sibling()->color = p->parent->color;
            p->parent->color = BLACK;
            if (p == p->parent->left) {
                p->sibling()->right->color = BLACK;
                rotateLeft(p->sibling());
            } else {
                p->sibling()->left->color = BLACK;
                rotateRight(p->sibling());
            }
        }
    }

    void DeleteTree(Node *p) {
        if (!p) return;

        DeleteTree(p->left);
        DeleteTree(p->right);
        delete p;
    }

public:
    RBTree():root(NULL){}

    ~RBTree() {
        DeleteTree(root);
    }

    void insert(int val) {
        if (root == NULL) {
            root = new Node(val);
            root->color = BLACK;
        } else {
            insert(root, val);
        }
    }

    bool delete_value(int val) {
        return delete_child(root, val);
    }

    void levelTraverse() {
        if (!root) return;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();
            cout << curr->val << "|" << curr->color << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }

private:
    Node *root;
};

int main()
{
    RBTree rbt;

    int a[] = {18, 8, 22, 4, 19, 24, 21, 23, 25, 26};
    for (auto &i : a) {
        rbt.insert(i);
    }
    rbt.levelTraverse();

    return 0;
}

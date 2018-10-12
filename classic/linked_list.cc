#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

struct Node {
    int val;
    Node *next;
};

Node* addSingleList(Node *root, int val) {
    if (!root) {
        Node *head = (Node *)malloc(sizeof(*head));
        head->val = val;
        head->next = NULL;
        return head;
    }
    Node *prev = root;
    while (prev->next) prev = prev->next;
    Node *nn = (Node *)malloc(sizeof(*nn));
    nn->val = val;
    nn->next = NULL;
    prev->next = nn;

    return root;
}

void freeSingleList(Node *root) {
    while (root) {
        Node *cur = root;
        root = root->next;
        free(cur);
    }
}

void printSingleList(Node *root) {
    Node *head = root;
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseSingleList(Node *root) {
    Node *prev = NULL;
    Node *head = root;
    while (head) {
        Node *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

Node* getSingleListInverseNode(Node *root, int k) {
    Node *prev = NULL, *curr = root;
    while (k-- && curr) curr = curr->next;
    if (curr) {
        prev = root;
    }
    while (curr) {
        curr = curr->next;
        prev = prev->next;
    }
    return prev;
}

Node* getSingleListMiddle(Node *root) {
    Node *prev = root, *curr = root;
    while (curr && curr->next) {
        curr = curr->next->next;
        prev = prev->next;
    }

    return prev;
}

bool checkSingleListLoop(Node *root) {
    if (!root || !root->next) return false;

    Node *p1 = root, *p2 = root->next->next;
    while (p2 && p2->next) {
        if (p1 == p2) return true;
        p1 = p1->next;
        p2 = p2->next->next;
    }

    return false;
}

bool check2SingleListCross(Node *lh, Node *rh) {
    Node *ltail = lh;
    while (ltail->next) ltail = ltail->next;

    Node *rtail = rh;
    while (rtail->next) rtail = rtail->next;

    return ltail == rtail;
}

Node* get2SingleListFirstCross(Node *lh, Node *rh) {
    if (!check2SingleListCross(lh, rh)) return NULL;

    int llen = 0, rlen = 0;
    for (Node *t = lh; t; llen++, t=t->next);
    for (Node *t = rh; t; rlen++, t=t->next);

    Node *tlh = lh, *trh = rh;
    if (llen > rlen) {
        for (; llen > rlen; tlh = tlh->next, llen--);
    } else if (llen < rlen) {
        for (; rlen > llen; trh = trh->next, rlen--);
    }
    while (tlh && trh && tlh != trh) {
        tlh = tlh->next;
        trh = trh->next;
    }

    return tlh;
}

Node* getSingleListLoopFirstNode(Node *root) {
    if (!root || !root->next) return NULL;

    bool isLoop = false;
    Node *p1 = root, *p2 = root->next->next;
    while (p2 && p2->next) {
        if (p1 == p2) {
            isLoop = true;
            break;
        }
        p1 = p1->next;
        p2 = p2->next->next;
    }
    if (!isLoop) return NULL;

    Node *troot = p1->next;
    p1->next = NULL;

    Node *result = get2SingleListFirstCross(root, troot);
    p1->next = troot;

    return result;
}

int main()
{
    Node *root = addSingleList(NULL, 1);
    root = addSingleList(root, 2);
    root = addSingleList(root, 3);
    root = addSingleList(root, 4);
    root = addSingleList(root, 5);
    root = addSingleList(root, 6);
    root = addSingleList(root, 7);

    /* 环检测
    root->next->next->next = root->next;
    cout << checkSingleListLoop(root) << endl;

    // 换入口点
    Node *first = getSingleListLoopFirstNode(root);
    if (first) {
        cout << "loop first " << first->val << endl;
    }
    */

    /*
    Node *rroot = reverseSingleList(root);
    printSingleList(rroot);
    */

    /*
    Node *rk = getSingleListInverseNode(root, 3);
    if (rk) {
        cout << "reverse 3: " << rk->val << endl;
    }

    Node *mid = getSingleListMiddle(root);
    if (mid) {
        cout << "middle: " << mid->val << endl;
    }
    */

    /*
    Node *root1 = addSingleList(NULL, 11);
    root1->net = root->next;
    cout << check2SingleListCross(root, root1) << endl;
    */
}

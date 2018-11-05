#include <iostream>
using namespace std;
static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node *root = head;
        while (root) {
            while (root && !root->child) {
                root = root->next;
            }
            if (!root) break;

            Node *flap = flatten(root->child);
            Node *flapTail = flap;
            while (flapTail->next) flapTail = flapTail->next;
            flapTail->next = root->next;
            if (root->next) {
                root->next->prev = flapTail;
            }
            root->next = flap;
            flap->prev = root;
            root->child = NULL;

            root = root->next;
        }

        return head;
    }
};

int main()
{
    Node *r1 = new Node(1, NULL, NULL, NULL);
    Node *r2 = new Node(2, r1, NULL, NULL);
    Node *r3 = new Node(3, r2, NULL, NULL);
    Node *r4 = new Node(4, r3, NULL, NULL);
    Node *r5 = new Node(5, r4, NULL, NULL);
    Node *r6 = new Node(6, r5, NULL, NULL);
    r1->next = r2;
    r2->next = r3;
    r3->next = r4;
    r4->next = r5;
    r5->next = r6;

    Node *r7 = new Node(7, NULL, NULL, NULL);
    Node *r8 = new Node(8, r7, NULL, NULL);
    Node *r9 = new Node(9, r8, NULL, NULL);
    Node *r10 = new Node(10, r9, NULL, NULL);
    r7->next = r8;
    r8->next = r9;
    r9->next = r10;

    Node *r11 = new Node(11, NULL, NULL, NULL);
    Node *r12 = new Node(12, r11, NULL, NULL);
    r11->next = r12;

    r3->child = r7;
    r8->child = r11;

    Solution s;
    Node *head = s.flatten(r1);

    Node *root = head;
    while (root) {
        cout << root->val << " ";
        root= root->next;
    }
    cout << endl;

    root = head;
    while (root->next) root = root->next;

    while (root) {
        cout << root->val << " ";
        root = root->prev;
    }
    cout << endl;
}

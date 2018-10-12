#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode* _merge(ListNode *root1, ListNode *root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        ListNode *ret = NULL, *head = NULL;
        while (root1 && root2) {
            if (root1->val < root2->val) {
                if (!head) {
                    ret = root1;
                    head = root1;
                } else {
                    head->next = root1;
                    head = root1;
                }
                root1 = root1->next;
            } else {
                if (!head) {
                    ret = root2;
                    head = root2;
                } else {
                    head->next = root2;
                    head = root2;
                }
                root2 = root2->next;
            }
        }

        head->next = !root1 ? root2 : root1;
        return ret;
    }
    ListNode* sortList(ListNode *head) {
        if (!head || !head->next) return head;
        if (!head->next->next) {
            if (head->next->val < head->val) {
                ListNode *n = head->next;
                head->next = NULL;
                n->next = head;
                return n;
            } else {
                return head;
            }
        }

        ListNode *p = head, *q = head->next->next;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
        }

        ListNode *mid = p->next;
        p->next = NULL;
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return _merge(left, right);
    }
};

int main()
{
    ListNode *root = new ListNode(-1);
    root->next = new ListNode(5);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(0);

    Solution s;
    root = s.sortList(root);
    while (root) {
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

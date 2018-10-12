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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *nhead = NULL;
        ListNode *root = head;
        while (root) {
            ListNode *curr = root->next;
            if (!curr) break;

            if (root->val == curr->val) {
                while (curr && root->val == curr->val) {
                    curr = curr->next;
                }
                nhead = curr;
                root = curr;
            } else {
                ListNode *ncurr = curr->next;
                while (ncurr && curr->val == ncurr->val) {
                    ncurr = ncurr->next;
                }
                if (!nhead) nhead = root;
                if (curr->next == ncurr) {
                    root = curr;
                } else {
                    root->next = ncurr;
                }
            }
        }
        return nhead;
    }
};

int main()
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(1);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(3);

    Solution s;
    ListNode *head = s.deleteDuplicates(root);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

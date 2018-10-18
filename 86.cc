#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};

const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode *root = head;
        while (root && root->next) {
            if (root->val >= x) {
                ListNode *tmp = root->next;
                while (tmp && tmp->val >= x) {
                    tmp = tmp->next;
                }
                if (!tmp) break;

                int val = root->val;
                tmp = root->next;
                while (tmp && tmp->val >= x) {
                    swap(val, tmp->val);
                    tmp= tmp->next;
                }
                root->val = tmp->val;
                tmp->val = val;
            }
            root = root->next;
        }

        return head;
    }
};

int main()
{
    //1->4->3->2->5->2
    ListNode *root = new ListNode(1);
    root->next = new ListNode(4);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(6);
    root->next->next->next->next = new ListNode(5);
    root->next->next->next->next->next = new ListNode(7);

    Solution s;
    ListNode *head = s.partition(root, 3);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


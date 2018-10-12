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
    ListNode *oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;

        ListNode *evenHead = head->next;
        ListNode *odd = head, *even = head->next;
        while (even) {
            odd->next = even->next;
            if (!even->next) break;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

int main()
{
    ListNode *root = new ListNode(1);
    //root->next = new ListNode(2);
    //root->next->next = new ListNode(3);
    //root->next->next->next = new ListNode(4);
    //root->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode *head = s.oddEvenList(root);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

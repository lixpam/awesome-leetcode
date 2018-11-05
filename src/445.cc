#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int addwithcarry(ListNode* l1, int len1, ListNode *l2, int len2) {
        int carry = 0;
        if (l1->next) {
            if (len1 > len2) {
                carry = addwithcarry(l1->next, len1-1, l2, len2);
            } else {
                carry = addwithcarry(l1->next,len1-1, l2->next, len2-1);
            }
        } 
        if (len1 > len2) {
            l1->val += carry;
        } else {
            l1->val += l2->val + carry;
        }
        carry = l1->val/10;
        l1->val %= 10;
        return carry;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1->next && l1->val == 0) return l2;
        if (!l2->next && l2->val == 0) return l1;
        int len1 = 0, len2 = 0;
        ListNode *head1 = l1, *head2 = l2;
        while (head1){
            len1++;
            head1 = head1->next;
        }
        while (head2){
            len2++;
            head2 = head2->next;
        }

        head1 = len1 > len2 ? l1 : l2;
        head2 = len1 > len2 ? l2 : l1;
        ListNode *root = head1;
        if (len1 < len2) swap(len1, len2);

        int carry = addwithcarry(head1, len1, head2, len2);
        if (carry) {
            ListNode *nroot = new ListNode(carry);
            nroot->next = root;
            return nroot;
        }
        return root;
    }
};

int main()
{
    // (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
    
    ListNode *root1 = new ListNode(1);

    ListNode *root2 = new ListNode(9);
    root2->next = new ListNode(9);

    Solution s;
    ListNode *ret = s.addTwoNumbers(root1, root2);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;
}

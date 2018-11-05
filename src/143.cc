#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        unordered_map<int, ListNode*> m;
        int len = 0;
        for (ListNode *t = head; t; len++, t = t->next) {
            m[len] = t;
        }
        ListNode *root = head;
        ListNode *cur = root->next;
        int end = len-1;
        while (end > len/2) {
            cur = root->next;
            root->next = m[end];
            root->next->next = cur;
            root = cur;
            end--;
        }
        m[end]->next = NULL;
    }
};

int main()
{
    ListNode *root = new ListNode{1};

    Solution s;
    s.reorderList(root);
}

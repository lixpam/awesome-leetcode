#include <iostream>
#include <vector>
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        if (!root) return vector<ListNode*>(k, NULL);
        int len = 0;
        ListNode *head = root;
        while (head) {
            len++;
            head = head->next;
        }

        head = root;
        int avg = len/k;
        int carry = len%k;
        vector<ListNode *> ret;
        for (int i = 0; i < k; ++i) {
            int size = avg + (i < carry ? 1 : 0);
            if (size == 0) {
                ret.push_back(NULL);
            } else {
                ret.push_back(head);
                while (size > 1) {
                    head = head->next;
                    size--;
                }
                ListNode *tmp = head->next;
                head->next = NULL;
                head = tmp;
            }
        }

        return ret;
    }
};

int main()
{
    Solution s;
    ListNode *root = new ListNode(1);
    ListNode *head = root;
    for (int i = 2; i <= 10; ++i) {
        head->next = new ListNode(i);
        head = head->next;
    }

    vector<ListNode *> ret = s.splitListToParts(root, 11);
    for (auto &it : ret) {
        if (it == NULL) {
            cout << "null" << endl;
        } else {
            while (it) {
                cout << it->val << " ";
                it = it->next;
            }
            cout << endl;
        }
    }
}

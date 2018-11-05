#include <iostream>
#include <vector>
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
    int numComponents(ListNode* head, vector<int>& G) {
        vector<bool> status(10001, false);
        for (auto &it : G) {
            status[it] = true;
        }

        int sect = 0;
        ListNode *tmp = head;
        while (tmp) {
            if (status[tmp->val]) {
                sect++;
                for (tmp = tmp->next; tmp && status[tmp->val]; tmp = tmp->next);
            }
            for (; tmp && !status[tmp->val]; tmp = tmp->next);
        }
        return sect;
    }
};

int main()
{
    ListNode *root = new ListNode(0);
    root->next = new ListNode(1);
    root->next->next = new ListNode(2);
    root->next->next->next = new ListNode(3);
    root->next->next->next->next = new ListNode(4);

    vector<int> g{0,3,1,4};
    Solution s;
    cout << s.numComponents(root, g) << endl;
}

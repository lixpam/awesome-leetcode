#include <iosstream>
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

const static int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> old2new;
        
        RandomListNode *root = new RandomListNode{head->label};
        old2new[head] = root;
        
        RandomListNode *ohead = head;
        RandomListNode *nhead = root;
        while (ohead->next) {
            ohead = ohead->next;
            RandomListNode *n = new RandomListNode{ohead->label};
            nhead->next = n;
            nhead = n;
            
            old2new[ohead] = nhead;
        }
        
        ohead = head;
        nhead = root;
        while (ohead) {
            if (ohead->random) {
                nhead->random = old2new[ohead->random];
            }
            
            ohead = ohead->next;
            nhead = nhead->next;
        }
        
        return root;
    }
};
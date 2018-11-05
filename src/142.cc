static const int _ = [](){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	if (!head || !head->next || !head->next->next) return NULL;
    	ListNode *p1 = head, *p2 = head->next->next;
    	bool isLoop = false;
    	while (p2 && p2->next) {
    		if (p1 == p2) {
    			isLoop = true;
    			break;
    		}
    		p1 = p1->next;
    		p2 = p2->next->next;
    	}
    	if (!isLoop) return NULL;

        ListNode *root1 = head;
        while (root1 != p1) {
            root1 = root1->next;
            p1 = p1->next;
        }
        return p1;
    }
};

#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;

        UndirectedGraphNode *nn = new UndirectedGraphNode(node->label);

        for (auto it : node->neighbors) {
            nn->neighbors.push_back(cloneGraph(it));
        }
        
        return nn;
};

int main()  {
    Solution s;
}

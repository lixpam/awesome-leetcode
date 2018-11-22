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

        if (nodes.find(node) == nodes.end()) {
            nodes[node] = new UndirectedGraphNode(node->label);
            int len = node->neighbors.size();
            (nodes[node])->neighbors.assign(len, nullptr);

            for (int i = 0; i < len; ++i) {
                (nodes[node])->neighbors[i] = cloneGraph(node->neighbors[i]);
            }
        }
        return nodes[node];
    }
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodes;
};

int main()  {
    Solution s;

    UndirectedGraphNode root{0};
    UndirectedGraphNode node1{1};
    UndirectedGraphNode node2{2};
    root.neighbors.push_back(&node1);
    root.neighbors.push_back(&node2);
    node1.neighbors.push_back(&node2);
    node2.neighbors.push_back(&node2);

    UndirectedGraphNode *clone = s.cloneGraph(&root);

    return 0;
}

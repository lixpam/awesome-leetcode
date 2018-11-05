#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
using namespace std;

class Graph {
public:
    // 有向无权图
    Graph(vector<pair<int, pair<int, int>>> &edges) {
        for (auto &it : edges) {
            _adj[it.first].push_front({it.second.first, it.second.second});
        }
    }
    ~Graph() {}

    void topSort() const;           // 拓扑排序
    void unweight(unordered_map<int, pair<int, int>> &dist, int start);    // 无权图最短路径
    void dijkstra(unordered_map<int, pair<int, int>> &dist, int start);    // 有向赋权图的最短路径
private:
    void initPath(unordered_map<int, pair<int, int>> &dist, int start) {
        unordered_set<int> _nodes;
        for (auto &it : _adj) {
            _nodes.insert(it.first);
            for (auto &_l : it.second) {
                _nodes.insert(_l.v);
            }
        }
        for (auto &v : _nodes) {
            dist[v] = pair<int, int>{v == start ? 0 : INT_MAX, 0};
        }
    }
    // help function
    void printIndegree(const unordered_map<int, int> &indegree) const {
        cout << "Indegree List\n";
        for (auto &it : indegree) {
            cout << it.first << " : " << it.second << endl;
        }
    }
private:
    // 邻接点
    struct AdjNode {
        int v;
        int weight;
    };
    // 邻接表(adjacency list)
    unordered_map<int, list<AdjNode>> _adj;         // node_val->edge other node
};

// 拓扑排序
// 找到入度为0的入队列，找到相邻的边节点，入度减一，并将新入度为0的入队列，重复之
void Graph::topSort() const {
    unordered_map<int, int> indegree;       
    for (auto &it : _adj) {
        indegree[it.first] = 0;
    }

    for (auto &it : _adj) {
        for (auto &edge : it.second) {
            indegree[edge.v]++;
        }
    }

    printIndegree(indegree);

    queue<int> q;
    for (auto &it : indegree) {
        if (it.second == 0) {
            q.push(it.first);
        }
    }

    queue<int> output;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        output.push(tmp);

        auto _l = _adj.find(tmp);
        if (_l != _adj.end()) {
            for (auto &it : _l->second) {
                if (--indegree[it.v] == 0)
                    q.push(it.v);
            }
        }
    }

    while (!output.empty()) {
        cout << output.front() << " ";
        output.pop();
    }
    cout << endl;
}

// 无权图最短路径
// start：开始点
// t：其他点->(路径，上次连接点)
// 广度优先搜索
void Graph::unweight(unordered_map<int, pair<int, int>> &t, int start) {
    // 其他点路径赋值无穷大, 起始点路径0
    initPath(t, start);

    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();

        for (auto &it : _adj[tmp]) {
            if (t[it.v].first == INT_MAX) {
                t[it.v].first = t[tmp].first + 1;
                t[it.v].second = tmp;

                q.push(it.v);
            }
        }
    }
}

// 有向赋权图最短路径
// start: 开始点
// t：其他点->(权重，上次连接点)
// 广度优先搜索
void Graph::dijkstra(unordered_map<int, pair<int,int>> &dist, int start) {
    initPath(dist, start);

    struct cmp {
        bool operator() (const pair<int, int>&lhs, const pair<int,int>&rhs) {
            return lhs.second < rhs.second;
        };
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        const pair<int, int> &tmp = pq.top();
        pq.pop();

        int v = tmp.first, weight = tmp.second;
        for (auto &it : _adj[v]) {
            if (weight + it.weight < dist[it.v].first) {
                dist[it.v].first = weight + it.weight;
                dist[it.v].second = v;

                pq.push({it.v, dist[it.v].first});
            }
        }
    }
}

int main()
{
    /*
    vector<pair<int,int>> edges = {
        {1, {2, 1}},
        {1, {3, 1}},
        {1, {4, 1}},
        {2, {4, 1}},
        {2, {5, 1}},
        {3, {6, 1}},
        {4, {3, 1}},
        {4, {6, 1}},
        {4, {7, 1}},
        {5, {4, 1}},
        {5, {7, 1}},
        {7, {6, 1}},
    };
    Graph graph(edges);
    graph.topSort();
    */
    /*
    vector<pair<int, pair<int, int>>> edges = {
        {1, {2, 1}},
        {1, {4, 1}},
        {2, {4, 1}},
        {2, {5, 1}},
        {3, {1, 1}},
        {3, {6, 1}},
        {4, {3, 1}},
        {4, {5, 1}},
        {4, {6, 1}},
        {4, {7, 1}},
        {5, {7, 1}},
        {7, {6, 1}},
    };

    Graph graph(edges);
    unordered_map<int, pair<int, int>> weight;
    graph.unweight(weight, 3);
    for (auto &it : weight) {
        cout << it.first << " "  << it.second.first << " " << it.second.second << endl;
    }
    */
    vector<pair<int, pair<int, int>>> edges = {
        {1, {2, 2}},
        {1, {4, 1}},
        {2, {4, 3}},
        {2, {5, 10}},
        {3, {1, 4}},
        {3, {6, 5}},
        {4, {3, 2}},
        {4, {5, 2}},
        {4, {6, 8}},
        {4, {7, 4}},
        {5, {7, 6}},
        {7, {6, 1}},
    };

    Graph graph(edges);
    unordered_map<int, pair<int, int>> weight;
    graph.dijkstra(weight, 1);
    for (auto &it : weight) {
        cout << it.first << " "  << it.second.first << " " << it.second.second << endl;
    }
}


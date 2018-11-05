#include <iostream>
#include <map>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class FreqStack {
private:
    struct Node {
        int val;
        int cnt;
        Node(int val):val(val),cnt(1){}
    };
public:
    FreqStack() {
    }
    
    void push(int x) {
        auto it = val2node.find(x);
        Node *n = NULL;
        if (it == val2node.end()) {
            n = new Node(x);
            val2node[x] = n;
        } else {
            n = it->second;
            n->cnt++;
        }
        elems.push_back(n);
        
        if (n->cnt != 1) {
            auto &f = freqlist[n->cnt-1];
            f.erase(n->val);
            if (f.size() == 0) {
                freqlist.erase(n->cnt-1);
            }
        }
        auto &f1 = freqlist[n->cnt];
        f1.insert(n->val);
    }
    
    int pop() {
        auto &fl = freqlist.begin()->second;
        for (auto b = elems.rbegin(); b != elems.rend(); ++b) {
            int val = (*b)->val;
            int cnt = (*b)->cnt;
            if (fl.find(val) != fl.end()) {
                auto &f = freqlist[cnt];
                f.erase(val);
                if (f.size() == 0) {
                    freqlist.erase(cnt);
                }
                (*b)->cnt--;
                cnt--;
                elems.erase((++b).base());
                if (cnt > 0) {
                    freqlist[cnt].insert(val);
                } else {
                    val2node.erase(val);
                }
                
                return val;
            }
        }
    }
private:
    vector<Node*> elems;
    unordered_map<int, Node*> val2node;                 // x->node
    map<int, unordered_set<int>, greater<int> > freqlist;     // freq->x
};

int main()
{
    FreqStack fs;
    fs.push(5);
    fs.push(7);
    fs.push(5);
    fs.push(7);
    fs.push(4);
    fs.push(5);

    cout << fs.pop() << endl;
    cout << fs.pop() << endl;
    cout << fs.pop() << endl;
    cout << fs.pop() << endl;
}

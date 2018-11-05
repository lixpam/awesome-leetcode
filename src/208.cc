#include <iostream>

using namespace std;

static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

struct Node
{
    bool tail;
    Node* childs[26];
    Node() {
        tail = false;
        for (int i = 0; i < 26; ++i){
            childs[i] = NULL;
        }
    }
};

class Trie{
public:
    void insert(string word) {
        Node *r = &root;
        for (char &c : word) {
            int index = c-'a';
            if (!r->childs[index]) {
                r->childs[index] = new Node;
            }
            r = r->childs[index];
        }
        r->tail = true;
    }
        
    bool search(string word) {
        return _search(&root, false, word.c_str(), word.length());
    }

    bool startsWith(string prefix) {
        return _search(&root, true, prefix.c_str(), prefix.length());
    }
private:
    Node root;

    bool _search(Node *r, bool prefix, const char *w, int len) {
        if (!r) return false;
        if (len == 0) return prefix || r->tail;

        int index = w[0]-'a';
        return _search(r->childs[index], prefix, w+1, len-1);
    }
};

int main()
{
    Trie w;
    w.insert("apple");
    cout << w.search("apple") << endl;
    cout << w.search("app") << endl;
    cout << w.startsWith("app") << endl;

    w.insert("app");
    cout << w.search("app") << endl;
    cout << w.startsWith("app") << endl;
}

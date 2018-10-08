#include <iostream>
#include <unordered_map>

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

class WordDictionary {
public:
    void addWord(string word) {
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

    bool _search(Node *r, const char *w, int len) {
        if (!r) return false;
        if (len == 0) return r->tail;

        if (w[0] != '.') {
            int index = w[0]-'a';
            return _search(r->childs[index], w+1, len-1);
        } else {
            for (int i = 0; i < 26; ++i) {
                if (r->childs[i] && _search(r->childs[i], w+1, len-1)) return true;
            }
        }
        return false;
    }
        
    bool search(string word) {
        return _search(&root, word.c_str(), word.length());
    }
private:
    Node root;
};

int main()
{
    WordDictionary w;
    w.addWord("at");
    w.addWord("and");
    w.addWord("an");
    w.addWord("add");

    w.addWord("bat");
    cout << w.search(".") << endl;

    cout << w.search(".at") << endl;
    cout << w.search("an.") << endl;
    cout << w.search("a.d.") << endl;
    cout << w.search("b.") << endl;
    cout << w.search("a.d") << endl;
    cout << w.search(".") << endl;
}

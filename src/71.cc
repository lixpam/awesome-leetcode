#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void eltnextstr(string &path, int &start, string &out) {
        out.clear();
        int len = path.size();
        start++;    // skip /
        while (start < len && path[start] != '/') {
            out += path[start++];
        }
    }

    string output(stack<string> s) {
        if (s.empty()) return "";

        string tmp = s.top();
        s.pop();

        return output(s) + "/" + tmp;
    }

    string simplifyPath(string path) {
        stack<string> s;

        int len = path.size();
        int start = 0;
        string snip;
        while (start < len) {
            eltnextstr(path, start, snip);
            if (snip.size() != 0 && snip != ".") {
                if (snip == ".." && !s.empty()) {
                    s.pop();
                } 
                if (snip != "..") {
                    s.push(snip);
                }
            }
        }

        if (s.empty()) return "/";
        return output(s);
    }
};

int main()  {
    Solution s;
    cout << s.simplifyPath("/home/") << endl;
    cout << s.simplifyPath("/a/./b/../../c/") << endl;
    cout << s.simplifyPath("/a/../../b/../c//.//") << endl;
    cout << s.simplifyPath("/a//b////c/d//././/..") << endl;
    cout << s.simplifyPath("/../") << endl;
    cout << s.simplifyPath("/home//foo/") << endl;
}

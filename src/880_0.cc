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
    string decodeAtIndex(string s, int k) {
        long size = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (isdigit(s[i])) 
                size *= (s[i]-'0');
            else
                size++;
        }

        for (int i = len-1; i>= 0; --i) {
            k %= size;
            if (k == 0 && isalpha(s[i]))
                return string(1, s[i]);

            if (isdigit(s[i])) 
                size /= (s[i]-'0');
            else
                size--;
        }
    }
};

int main()  {
    Solution s;
    cout << s.decodeAtIndex("ixm5xmgo78", 711) << endl;
    //cout << s.decodeAtIndex("ha22", 5) << endl;
    //cout << s.decodeAtIndex("a2345678999999999999999", 1) << endl;
    cout << s.decodeAtIndex("a23", 6) << endl;
}

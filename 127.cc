#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void addNext(string &word, unordered_set<string>& wordList, queue<string>& vist) {
        wordList.erase(word);

        int len = word.size();
        for (int i = 0; i < len; ++i) {
            char c = word[i];
            for (char x = 'a'; x <= 'z'; ++x) {
                word[i] = x;
                if (wordList.find(word) != wordList.end()) {
                    vist.push(word);
                    wordList.erase(word);
                }
            }
            word[i] = c;
        }
    }
    int ladderLengthWrap(string &beginWord, string &endWord, unordered_set<string>& wordList) {
        if (wordList.size() == 0) return 0;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

        queue<string> vist;
        addNext(beginWord, wordList, vist);

        int dist = 2;
        while (!vist.empty()) {
            int num = vist.size();
            for (int i = 0; i < num; ++i) {
                string s = vist.front();
                vist.pop();
                if (s == endWord) return dist;
                addNext(s, wordList, vist);
            }
            dist++;
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        return ladderLengthWrap(beginWord, endWord, s);
    }
};

int main()
{
    vector<string> arg{"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    //vector<string> arg{"hot","dot","dog","lot","log","cog"};

    Solution s;
    cout << s.ladderLength("qa", "sq", arg) << endl;
    //cout << s.ladderLength("hit", "cog", arg) << endl;
}

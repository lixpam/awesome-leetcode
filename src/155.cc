#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
        
    void push(int x) {
        data.push(x);
        if (minData.empty())
            minData.push(x);
        else if (minData.top() >= x)
            minData.push(x);
    }
        
    void pop() {
        if (data.top() == minData.top())
            minData.pop();
        data.pop();
    }
        
    int top() {
        return data.top();
    }
        
    int getMin() {
        return minData.top();
    }

private:
    stack<int> data;
    stack<int> minData;
};

int main()  {
    Solution s;
}

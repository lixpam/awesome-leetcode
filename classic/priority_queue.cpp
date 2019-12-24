#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// 默认大堆
template<typename T, typename Compare=std::less<T>>
class PriorityQueue {
public:
    PriorityQueue() {
        cmp = Compare();
    }

    void push(const T& val) {
        mVals.push_back(val);

        // up
        int i = mVals.size()-1;
        while (i > 0) {
            if (cmp(mVals[(i-1)/2], val)) {
                mVals[i] = mVals[(i-1)/2];
                i = (i-1)/2;
            } else {
                break;
            }
        }
        mVals[i] = val;
        cout << "push:";
        for (auto &iter : mVals )
            cout << iter << " ";
        cout << endl;
    }

    bool empty() {
        return mVals.empty();
    }

    T top() {
        return mVals[0];
    }

    void pop() {
        int size = mVals.size();
        T& _nval = mVals[size-1];

        size--;
        int i = 0, child = 2*i+1;
        // down
        for (; (2*i+1) < size; i = child) {
            child = 2*i+1;
            if (child < size-1 && cmp(mVals[child], mVals[child+1]))
                child++;
            if (!cmp(mVals[child], _nval)) {
                mVals[i] = mVals[child];
            } else {
                break;
            }
        }
        mVals[i] = _nval;

        mVals.pop_back();
    }

private:
    Compare cmp;
    vector<T> mVals;
};

int main() {
    PriorityQueue<int> pq;
    for (int i = 1; i <= 4; ++i) 
        pq.push(i);

    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
}

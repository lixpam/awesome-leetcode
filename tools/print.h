#ifndef __PRINT_H__
#define __PRINT_H__

#include <iostream>
using namespace std;

class SeqPrint {
public:
    template<class T>
    static void print(const T &arg) {
        for (auto &it : arg) {
            cout << it << " ";
        }
        cout << endl;
    }
};

#endif

#!/usr/bin/python
#!-*- coding:utf-8 -*-

import sys

template ='''#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

static const int _=[](){
    ios:sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
};

int main()  {

}
'''

def help():
    print "pyton gen_template.py title"

if __name__ == '__main__':
    if len(sys.argv) < 2:
        help()
        sys.exit(0)
    filename = sys.argv[1]
    with open(filename+".cc", "w") as fd:
        fd.write(template)

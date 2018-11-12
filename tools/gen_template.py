#!/usr/bin/python
#!-*- coding:utf-8 -*-

'''
add follow two lines to .bashrc
export LETC='/path/to/local/leetcode'
alias glc='_(){ cd $LETC/src && python ../tools/gen_template.py $1 && vi $1.cc +11;  }; _'

then you can use 'glc 880' in anywhere, 880 is title's number of leetcode
'''

import sys
import os

template ='''#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
};

int main()  {
    Solution s;
}
'''

def help():
    print "pyton gen_template.py title_number"

if __name__ == '__main__':
    if len(sys.argv) < 2:
        help()
        sys.exit(0)
    filename = sys.argv[1] + ".cc"
    if os.path.exists(filename):
        sys.exit(0)
    with open(filename, "w") as fd:
        fd.write(template)

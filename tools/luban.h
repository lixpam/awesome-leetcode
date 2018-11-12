#ifndef __LUBAN_H__
#define __LUBAN_H__

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

using veci = std::vector<int>;
using vecs = std::vector<std::string>;

using mapii = std::map<int, int>;
using mapis = std::map<int, std::string>;
using mapss = std::map<std::string, std::string>;

template <typename T>
void prints(const T &t) {
    for (auto &it : t) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printm(const T &m) {
    for (auto &it : m) {
        std::cout << it.first << " : " << it.second << " ";
    }
    std::cout << std::endl;
}

#endif

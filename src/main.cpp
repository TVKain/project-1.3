#include <iostream>
#include <string>

#include <functional>

#include "hash_table.hpp"
#include "linked_list.hpp"


int main() {
    ds::hash_table<int, int> a;

    a.insert({1, 2});
    a.insert({10, 1000});
    a.insert({100, 10000});

    for (auto &it : a) {
        it.second = 69;
    }

    for (const auto &it : a) {
        std::cout << it.second << std::endl;
    }
    return 0;
}
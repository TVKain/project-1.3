#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "hash_table.hpp"
#include "linked_list.hpp"



int main() {
    ds::hash_table<int, int> a = {{10, 2}, {100, 3}};

    ds::hash_table<int, int> b;

    b = a;

    for (const auto &it : b) {
        std::cout << it.first << std::endl;
    }

    std::cout << b.size() << std::endl;

    return 0;
}
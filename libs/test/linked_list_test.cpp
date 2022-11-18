#include "linked_list.hpp"
#include <iostream>
#include <memory>
#include <vector>

int main() {
    linked_list<int> b;
    b.push_back(4);
    b.push_back(3);
    b.push_back(2);

    b.erase(b.begin());
    b.erase(b.begin());
    b.erase(b.begin());
 

    return 0;
}
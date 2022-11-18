#include "linked_list.hpp"
#include <iostream>
#include <memory>
#include <vector>


int main() {
    ds::linked_list<int> b = {10, 7, 5, 2};
    
    for (auto it : b) {
        std::cout << it << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::list<int> b = {1,2,3};
    b.erase(b.begin());
    b.erase(b.begin());
    b.erase(b.begin());
    b.erase(b.begin());


    return 0;
}
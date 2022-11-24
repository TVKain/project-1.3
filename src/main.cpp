#include "menu.hpp"
#include <string>
#include <cctype>

std::string get_word(std::string &str);

int main() {
    std::string a = "Hello; hi 'end', beginning to the end";

    std::string w = get_word(a);

    std::cout << w << std::endl;
    std::cout << a << std::endl;

    std::cout << get_word(a) << std::endl;
    std::cout << a << std::endl;

    std::cout << get_word(a) << std::endl;
    std::cout << a << std::endl;

    return 0;
}


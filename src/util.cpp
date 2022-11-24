#include "util.hpp"

#include <string>
#include <cctype>

namespace ds {
    std::string get_word(std::string &str) {
        int i = 0; 
        std::string ret;

        // Skip non alphanumeric
        while (!std::isalpha(str[i])) {
            ++i;
        }

        // Read alpha
        while (std::isalpha(str[i])) {
            ret += std::tolower(str[i]);
            ++i;
        }
        
        str.erase(0, i);

        return ret;
    }
}

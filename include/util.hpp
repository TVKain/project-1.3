#pragma once
#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>

#define clear_input() std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') 


namespace util {
    std::string get_word(std::string &str);
}


#endif
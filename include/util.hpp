#pragma once
#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>


#include "array_list.hpp"

#define clear_input() std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') 


namespace util {
    std::string get_word(std::string *str);

    std::string get_current_time();

    ds::array_list<std::string> get_words(std::string str);
}


#endif
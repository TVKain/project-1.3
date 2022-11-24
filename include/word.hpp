#pragma once
#ifndef WORD_HPP
#define WORD_HPP

#include <iostream>
#include <string>

#include "linked_list.hpp"
#include "array_list.hpp"


struct word {
    std::string key_word;   
    ds::linked_list<int> line_list;
    int occurrence = 0;

    friend std::ostream& operator<<(std::ostream &os, word &w) {
        os << w.key_word;
        
        for (auto &it : w.line_list) {
            os << ", " << it;
        }
        return os;
    }

    bool operator==(const word &other) {
        return key_word == other.key_word;
    }

    bool operator>(const word &other) {
        return key_word > other.key_word;
    }

    bool operator<(const word &other) {
        return key_word < other.key_word;
    }
};


#endif
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

    word() : occurrence(0), key_word(std::string()), line_list(ds::linked_list<int>()) {}
    word(const std::string &t_key_word) : key_word(t_key_word) {}

    friend std::ostream& operator<<(std::ostream &os, const word &w) {
        os << w.occurrence << " ";
        os << w.key_word;
        
        for (auto &it : w.line_list) {
            os << ", " << it;
        }
        return os;
    }

    bool operator==(const word &other) const {
        return key_word == other.key_word;
    }

    bool operator>(const word &other) const {
        return key_word > other.key_word;
    }

    bool operator<(const word &other) const {
        return key_word < other.key_word;
    }
};


#endif
#pragma once
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <fstream>
#include <string>

#include "util.hpp"
#include "word.hpp"

#include "array_list.hpp"
#include "hash_table.hpp"
#include "binary_search_tree.hpp"
#include "linked_list.hpp"

class menu {
private:
    enum class container_type {LINKED_LIST = 1, HASH_TABLE = 2, BINARY_TREE = 3};

    int choice;
    bool text_flag = false;
    bool stop_word_flag = false;
    bool container_flag = false;

    container_type container;
    
    ds::array_list<word> a_words;
    ds::linked_list<word> ll_words;
    ds::hash_table<std::string, word> ht_words;
    ds::binary_search_tree<std::string, word> bst_words;

    ds::linked_list<std::string> stop_words;
public:
    void start_menu();
    
    void print_menu();
    void print_container();

    void get_choice();
    void get_text();
    void get_stop_word();
    void get_container();
    void generate_index();

    void read_to_linked_list(std::ifstream& file);
};






#endif
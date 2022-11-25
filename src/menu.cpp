#include "menu.hpp"

#include <algorithm>
#include <fstream>

#include "linked_list.hpp"
#include "sort.hpp"

void menu::start_menu() {
    for (;;) {
        print_menu();
        get_choice();

        if (choice == 1) {
            get_container();
        } else if (choice == 2) {
            get_stop_word();
        } else if (choice == 3) {
            get_text();
        } else if (choice == 4) {
            generate_index();
        } else {
            break;
        }
    }
}

void menu::print_menu() {
    std::cout << "\n        FILE INDEX" << std::endl;
    std::cout << "1. Choose container" << std::endl;
    std::cout << "2. Input stop word file" << std::endl;
    std::cout << "3. Input text file" << std::endl;
    std::cout << "4. Generate index file" << std::endl;
    std::cout << "5. Exit" << std::endl; 
}

void menu::print_container() {
    std::cout << "\n       CONTAINER" << std::endl;
    std::cout << "1. Linked List" << std::endl;
    std::cout << "2. Hash Table" << std::endl;
    std::cout << "3. Binary Search Tree" << std::endl;
    std::cout << "4. Return" << std::endl;
}

void menu::get_choice() {
    do {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        clear_input();
        if (choice < 1 || choice > 5) {
            std::cout << "Invalid choice" << std::endl;
        }
    } while (choice < 1 || choice > 5);
}

void menu::get_text() {
    ll_words.clear();
    ht_words.clear();
    bst_words.clear();

    if (!stop_word_flag) {
        std::cout << "Stop word file has not been set" << std::endl;
        return;
    }

    if (!container_flag) {
        std::cout << "Container type has not been set" << std::endl;
        return;
    }

    std::string file_name;

    std::cout << "Input file name: ";
    std::cin >> file_name;
    clear_input();

    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cout << "Could not open file: " << "'" << file_name  << "'" << std::endl;
        return;
    }

    switch (container) {
    case container_type::LINKED_LIST: 
        read_to_linked_list(file);
        break;
    case container_type::HASH_TABLE:
        read_to_hash_table(file);
    case container_type::BINARY_TREE: 
        read_to_binary_search_tree(file);
    default:
        break;
    }

    std::cout << "File: " << file_name << " has been read successfully" << std::endl;
    text_flag = true;
}  


void menu::read_to_linked_list(std::ifstream& file) {
    std::string line;

    int line_count = 1;
    while (std::getline(file, line)) {
        ds::array_list<std::string> words = util::get_words(line);

        for (auto &w : words) {
            if ((stop_words.find(w) != stop_words.end())) {
                continue;
            }

            auto curr = ll_words.find(word(w));

            if (curr == ll_words.end()) {
                word to_insert;
                to_insert.key_word = w;
                to_insert.occurrence = 1;
                to_insert.line_list.push_back(line_count);
                ll_words.insert_order(to_insert);
            } else {
                ++curr->occurrence;
                if (curr->line_list.back() != line_count) {
                    curr->line_list.push_back(line_count);
                }
            }
        }
        ++line_count;
    }
}

void menu::read_to_binary_search_tree(std::ifstream& file) {
    std::string line;

    int line_count = 1;
    while (std::getline(file, line)) {
        ds::array_list<std::string> words = util::get_words(line);

        for (auto &w : words) {
            if ((stop_words.find(w) != stop_words.end())) {
                continue;
            }

            auto curr = bst_words.find(w);

            if (curr == bst_words.end()) {
                word to_insert;
                to_insert.key_word = w;
                to_insert.occurrence = 1;
                to_insert.line_list.push_back(line_count);
                bst_words.insert({w, to_insert});
            } else {
                auto& mapped = curr->second;

                ++mapped.occurrence;
                if (mapped.line_list.back() != line_count) {
                    mapped.line_list.push_back(line_count);
                }
            }
        }
        ++line_count;
    }
}

void menu::read_to_hash_table(std::ifstream& file) {
    std::string line;

    int line_count = 1;
    while (std::getline(file, line)) {
        ds::array_list<std::string> words = util::get_words(line);

        for (auto &w : words) {
            if ((stop_words.find(w) != stop_words.end())) {
                continue;
            }

            auto curr = ht_words.find(w);

            if (curr == ht_words.end()) {
                word to_insert;
                to_insert.key_word = w;
                to_insert.occurrence = 1;
                to_insert.line_list.push_back(line_count);
                
                ht_words.insert({w, to_insert});
            } else {
                // If there's an element
                auto& mapped = curr->second;

                ++mapped.occurrence;
                if (mapped.line_list.back() != line_count) {
                    mapped.line_list.push_back(line_count);
                }
            }
        }
        ++line_count;
    }

}


void menu::get_stop_word() {
    stop_words.clear();

    std::string file_name;

    std::cout << "Input file name: ";
    std::cin >> file_name; 
    clear_input();

    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cout << "Could not open file: " << "'" << file_name << "'" << std::endl;
        return;
    }

    std::string buff;

    while (std::getline(file, buff)) {
        for (auto &c: buff) {
            c = std::tolower(c);
        }

        stop_words.push_back(buff);
    }

    std::cout << "File: " << file_name << " has been read successfully" << std::endl;
    stop_word_flag = true;
}

void menu::get_container() {
    print_container();
    int c_choice;

    do {
        std::cout << "Enter your choice: ";
        std::cin >> c_choice;
        clear_input();
        if (c_choice < 1 || c_choice > 4) {
            std::cout << "Invalid choice" << std::endl;
        }
    } while (c_choice < 1 || c_choice > 4);

    std::cout << std::endl;

    if (c_choice != 4) {
        container = static_cast<container_type>(c_choice);

        container_flag = true;
        switch (container) {
        case container_type::LINKED_LIST: 
            std::cout << "Linked List was chosen" << std::endl;
            break;
        case container_type::HASH_TABLE:
            std::cout << "Hash Table was chosen" << std::endl;
            break;
        case container_type::BINARY_TREE: 
            std::cout << "Binary Search Tree was chosen" << std::endl;
            break;
        default:
            break;
        }
    }
}

 void menu::generate_index() {
    if (!text_flag) {
        std::cout << "Input text file has not been set" << std::endl;
        return;
    }

    if (!stop_word_flag) {
        std::cout << "Stop word file has not been set" << std::endl;
        return;
    }

    if (!container_flag) {
        std::cout << "Container type has not been set" << std::endl;
        return;
    }

    std::string file_name = "index-" + container_to_string(container) + "-" + util::get_current_time() + ".txt";
    std::fstream file(file_name, std::ios::out);

    if (container == container_type::LINKED_LIST) {
        for (const auto &it : ll_words) {
            file << it << std::endl;
        }
    } else if (container == container_type::HASH_TABLE) {
        ds::array_list<word> a_words;
        for (auto &it : ht_words) {
            a_words.push_back(it.second);
        }

        algo::sort::quick_sort_iterative(a_words.begin(), a_words.end(), [](const auto &a, const auto &b) {
            return a.key_word < b.key_word;
        });

        for (const auto &it : a_words) {
            file << it << std::endl;
        }
    } else if (container == container_type::BINARY_TREE) {
        for (const auto &it : bst_words) {
            file << it.second << std::endl;
        }
    }

    std::cout << "Generate index file: " << file_name << std::endl;

    reset_all();
}

void menu::reset_all() {
    ll_words.clear();
    ht_words.clear();
    bst_words.clear();

    text_flag = false;
    stop_word_flag = false;
    container_flag = false;
}

std::string menu::container_to_string(container_type c) {
    std::string ret;
    
    switch (container) {
    case container_type::LINKED_LIST: 
        ret = "linked list";
        break;
    case container_type::HASH_TABLE:
        ret = "hash table";
        break;
    case container_type::BINARY_TREE: 
        ret = "binary search tree";
        break;
    default:
        break;
    }

    return ret;
}
#include "menu.hpp"

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

    //read_to_linked_list(file);
    text_flag = true;
}  



/*
void menu::read_to_linked_list(std::ifstream& file) {
    std::string line;


    while (std::getline(file, line)) {
        std::string current;

        int i = 0;

        while (i < line.length()) {
            current = get_word(line);

            break;
        }

    }

}

*/




void menu::get_stop_word() {
    std::string file_name;

    std::cout << "Input file name: ";
    std::cin >> file_name; 
    clear_input();

    std::ifstream file(file_name);

    std::string buff;

    if (!file.is_open()) {
        std::cout << "Could not open file: " << "'" << file_name << "'" << std::endl;
        return;
    }

    while (std::getline(file, buff)) {
        stop_words.push_back(buff);
    }
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

    std::cout << "Generate index" << std::endl;
}
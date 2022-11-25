#include "util.hpp"

#include <string>
#include <cctype>
#include <iostream>
#include <chrono>
#include <ctime>

#include "array_list.hpp"


namespace util {

    /***************************************
     * @brief: return current time as string
     ***************************************/
    std::string get_current_time() {
        auto now = std::chrono::system_clock::now();
        auto now_time = std::chrono::system_clock::to_time_t(now);
        
        char buff[30];
        std::strftime(buff, sizeof(buff), "%Hh%Mp%Ss %m-%d-%Y", std::localtime(&now_time));

        std::string ret(buff);

        return ret;
    }

    /********************************************************************
     * @brief: Extracts words from a string and put them in an array_list
     ********************************************************************/
    ds::array_list<std::string> get_words(std::string str) {
        std::size_t i = 0;

        ds::array_list<std::string> ret;

        std::string word;

        while (i < str.length()) {
            if (std::isalpha(str[i])) {
                word += std::tolower(str[i]);
            }

            if ((!std::isalpha(str[i]) || i == str.length() - 1) && !word.empty()) {
                ret.push_back(word);
                word.clear();
            }

            ++i;
        }

        return ret;
    }



    /****************************************************************************
     * @brief: Extract word by word from string kinda like strtok 
     * @param: std::string*
     *      Pointer to string to extract words
     *      If it's nullptr then it will try to extract word from previous string
     * @return: std::string
     *      Hold the word extracted
     * @usage: Similar to strtok
     *      std::string source = "A random string";
     *      std::string word = util::get_word(&source);
     *
     *      while (!word.empty()) {
     *          std::cout << word << std::endl;
     *          word = util::get_word(nullptr);
     *      }
     ****************************************************************************/
    std::string get_word(std::string *str) {     
        static std::string *ptr;
        static int index;

        if (str != nullptr) {
            ptr = str;
            index = 0;
        }

        std::string ret;

        while (index < ptr->length()) {
            if (!std::isalpha(ptr->at(index))) {
                ++index;
            } else {
                break;
            }
        }

        while (index < ptr->length()) {
            if (std::isalpha(ptr->at(index))) {
                ret += std::tolower(ptr->at(index));
                ++index;
            } else {
                break;
            }
        }

        return ret;
    }
}

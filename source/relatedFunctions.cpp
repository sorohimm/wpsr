//
// Copyright 2020 Vladimir Mashir
//
#include <header.h>

//void split(const std::string& str, char sep) {
//    std::vector<std::string> output;
//    if (!str.empty()) {
//        size_t prev_sep = 0;
//        while (str.find(sep, prev_sep) != std::string::npos &&
//               prev_sep < str.size()) {
//            size_t next_sep = str.find(sep, prev_sep);
//            if (next_sep != prev_sep) {
//                output.push_back(str.substr(prev_sep, next_sep - prev_sep));
//            }
//            prev_sep = ++next_sep;
//        }
//        if (str.substr(prev_sep).size() > 0) {
//            output.push_back(str.substr(prev_sep));
//        }
//    }
//}
//void addWordsToMap(const std::string& str, std::vector<std::string> output,  char sep) {
//    if (!str.empty()) {
//        size_t prev_sep = 0;
//        while (str.find(sep, prev_sep) != std::string::npos &&
//               prev_sep < str.size()) {
//            size_t next_sep = str.find(sep, prev_sep);
//            if (next_sep != prev_sep) {
//                output.push_back(str.substr(prev_sep, next_sep - prev_sep));
//            }
//            prev_sep = ++next_sep;
//        }
//        if (str.substr(prev_sep).size() > 0) {
//            output.push_back(str.substr(prev_sep));
//        }
//    }
//}

bool check(const char &input) {
    if (!std::isalpha(input) && input != ' ') {
        return true;
    }
    return false;
}

void formatLine(std::string &input) {
    for (auto i = input.begin(); i != input.end(); i++) {
        if (!std::isalpha(*i) && *i != ' ') {
            *i = ' ';
        }
    }
}

void split(std::string &input, std::vector<std::string> container) {
    boost::split(container, input, boost::algorithm::is_any_of(" "),
                 boost::algorithm::token_compress_on);
}


int deleteSingLet(std::string &input, int count) {
    for (auto i = input.begin(); i != input.end(); ++i) {
        if (std::isalpha(*i) && *i + 1 == ' ' && *i - 1 == ' ') {
            input.erase(i, i + 1);
            ++count;
        }
    }
    return count;
}

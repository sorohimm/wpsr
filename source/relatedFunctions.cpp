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
void split(const std::string &str, std::vector<std::string> output, char sep) {
    if (!str.empty()) {
        size_t prev_sep = 0;
        while (str.find(sep, prev_sep) != std::string::npos &&
               prev_sep < str.size()) {
            size_t next_sep = str.find(sep, prev_sep);
            if (next_sep != prev_sep) {
                output.push_back(str.substr(prev_sep, next_sep - prev_sep));
            }
            prev_sep = ++next_sep;
        }
        if (str.substr(prev_sep).size() > 0) {
            output.push_back(str.substr(prev_sep));
        }
    }
}

bool check(const char &input) {
    if (!std::isalpha(input) && input != ' ') {
        return true;
    }
    return false;
}

void formatLine(std::string &input) {
    for (auto i = input.begin(); i != input.end(); i++) {

        if (!std::isalpha(*i) && *i != ' ' &&
            !(*i == '\'' && std::isalpha(*(i - 1)) && std::isalpha(*(i - 1)))) {
            *i = ' ';
        }
    }
}

//void split(std::string &input, std::vector<std::string> container) {
//    boost::split(container, input, boost::algorithm::is_any_of(" "),
//                 boost::algorithm::token_compress_on);
//}


int deleteSingLet(std::string &input, int count) {
    for (auto i = input.begin(); i != input.end(); ++i) {
        if (std::isalpha(*i) && *i + 1 == ' ' && *i - 1 == ' ') {
            input.erase(i, i + 1);
            ++count;
        }
    }
    return count;
}
void deleteSpaces(std::string &input) {
    //    auto i = input.begin();
    //    do {
    //        if (*i == ' ' && !std::isalpha(*(i + 1))) {
    //            input.erase(i);
    //            ++i;
    //        }
    //        ++i;
    //    } while (i != input.end());

    for (auto i = input.begin(); i < input.end(); ++i) {
        if (*i == '*' && (!std::isalpha(*(i + 1)) || i + 1 != input.end())) {
            input.erase(i);
        }
    }
}

void star(std::string &input) {
    for (auto i = input.begin(); i < input.end(); ++i) {
        if (*i == ' ') {
            *i = '*';
        }
    }
}


void substtr(const std::string &str, std::vector<std::string> output) {
    if (str.empty()) {
        return;
    }
    size_t i = 0;
    size_t beg = 0;
    size_t end = 0;
    while (i != str.size()) {
        if (str[i] != ' ') {
            beg = i;
            while (std::isalpha(i + 1) || str[i] != '\n') {
                ++i;
            }
            end = i;
            output.push_back(str.substr(beg, end));
        } else {
            ++i;
        }
    }
}

void splitt(const std::string &str, std::vector<std::string> &ans, char sep) {

    std::string help;
    if (str.empty()) {
        return;
    }
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] != sep) {
            help += (str[i]);
        } else {
            if (!help.empty()) {
                ans.push_back(help);
                help.clear();
            }
        }
    }
    if (str[str.size() - 1] != sep) {
        ans.push_back(help);
    }
}

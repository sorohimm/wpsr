//
// Copyright 2020 Vladimir Mashir
//
#include <header.h>

void MakeStatic(vault &Statistics, std::ifstream &ClearText) {
    std::vector<std::string> tmp;
    std::string line;
    while (getline(ClearText, line)) {
        split(line, tmp, ' ');
        if (tmp.size() > 1) {
            for (auto i = tmp.begin(); i != tmp.end() - 1; i++) {
                if (Statistics[*i].find(*(i + 1)) != Statistics[*i].end()) {
                    ++Statistics[*i][*(i + 1)];
                } else {
                    Statistics[*i].emplace(*(i + 1), 1);
                }
            }
        }
    }
    //    tmp.clear();
}

bool CheckPair(const std::pair<std::string, int> &first,
               const std::pair<std::string, int> &second) {
    return (first.second > second.second);
}
void MapOutput(const vault &input, std::ofstream &file) {
    std::vector<std::pair<std::string, int>> tmpOut;
    for (const auto &key : input) {
        file << "^^^^ " << key.first << " ^^^^^" << std::endl;
        for (const auto &val : key.second) {
            tmpOut.emplace_back(make_pair(val.first, val.second));
        }
        std::sort(tmpOut.begin(), tmpOut.end(), CheckPair);
        for (const auto &value : tmpOut) {
            file << " # " << value.first << " - " << value.second;
        }
        file << std::endl;
        tmpOut.clear();
    }
}

void FileToVector(std::ifstream &InputFile, std::vector<std::string> &outputVector) {
    std::string line;
    while (getline(InputFile, line)) {
        split(line, outputVector, ' ');
    }
}


void formatLine(std::string &input) {
    for (auto i = input.begin(); i != input.end(); i++) {
        if (!std::isalpha(*i) && *i != ' ' &&
            !(*i == '\'' && std::isalpha(*(i - 1)) && std::isalpha(*(i - 1)))) {
            *i = ' ';
        } else {
            *i = tolower(*i);
        }
    }
}

void FormatFile(std::ifstream &inputFile, std::ofstream &outputFile) {
    std::string line;
    while (getline(inputFile, line)) {
        formatLine(line);
        outputFile << line << std::endl;
    }
}

void split(const std::string &str, std::vector<std::string> &ans, char sep) {

    std::string help;
    if (str.empty()) {
        return;
    }
    for (auto smb : str) {
        if (smb != sep) {
            help += (smb);
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

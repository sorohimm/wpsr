//
// Copyright 2020 Vladimir Mashir
//

#include <header.h>

int main() {
    //     ==================================================
    //     CLEANING
    //     ==================================================
    std::string line;
    std::ifstream inputFile("/Users/sorohimm/CLionProjects/untitled2/file.txt");
    if (!inputFile.is_open()) {
        std::cout << "ERROR!!! CAN NOT OPEN INPUT FILE" << std::endl;
    }
    std::ofstream outputFile("clearText.txt");
    if (!outputFile.is_open()) {
        std::cout << "ERROR!!! CAN NOT OPEN OUTPUT FILE" << std::endl;
    }
    while (getline(inputFile, line)) {
        formatLine(line);
        outputFile << line << std::endl;
    }
    outputFile.close();
    line.clear();

    //    //  =================================================
    //    // READ
    //    //  =================================================

    std::ifstream ClearText("/Users/sorohimm/CLionProjects/untitled2/cmake-build-debug/clearText.txt");
    if (!ClearText.is_open()) {
        std::cout << "ERROR!!! CAN NOT OPEN SCAN FILE" << std::endl;
    }

    vault mapa;
    std::vector<std::string> words;
    std::map<std::string, int> null;

    while (getline(ClearText, line)) {
        splitt(line, words, ' ');
    }
    for (size_t i = 0; i < words.size(); ++i) {
        mapa.emplace(words[i], null);
    }

    std::vector<std::string> tmp;
    while (getline(ClearText, line)) {
        splitt(line, tmp, ' ');
        for (auto i = tmp.begin(); i != tmp.end(); i++) {
            if (mapa[*i].find(*(i + 1)) == mapa[*i].end()) {
                ++mapa[*i][*(i + 1)];
            }
            mapa[*i].emplace(*i, 1);
        }
    }

    //  =================================================
    //  CUP OF CUM TO CUM FILE
    //  =================================================

    std::ofstream statTxt("statistic.txt");
    if (!statTxt.is_open()) {
        std::cout << "ERROR!!! CAN NOT OPEN OUTPUT FILE" << std::endl;
    }
    for (auto i = mapa.begin(); i != mapa.end(); ++i) {
        statTxt << "# " << i->first << " #" << std::endl;
        for (auto j = i->second.begin(); j != i->second.end(); ++j) {
            statTxt << "}" << j->first << "*" << j->second << "^^^^";
        }
    }
    return 0;
}

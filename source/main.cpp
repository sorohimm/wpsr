//
// Copyright 2020 Vladimir Mashir
//

#include <header.h>

int main() {
    std::string hh = ("привет как дела хуита ты ебаная");
    std::vector<std::string> output;
    split(hh, output);
    for (const auto& wrd : output) {
        std::cout << wrd << " ";
    }
    //
//    // ==================================================
//    // CLEANING
//    // ==================================================
//
//    /* std::ifstream inputFile("/Users/sorohimm/CLionProjects/untitled2/wiki.txt");
//    if (!inputFile.is_open()) {
//        std::cout << "ERROR!!! CAN NOT OPEN INPUT FILE" << std::endl;
//    }
//    std::ofstream outputFile("clearText.txt");
//    if (!outputFile.is_open()) {
//        std::cout << "ERROR!!! CAN NOT OPEN OUTPUT FILE" << std::endl;
//    } */
//    std::string line; /*
//    while (getline(inputFile, line)) {
//        getline(inputFile, line);
//        formatLine(line);
//        outputFile << line;
//    }
//    outputFile.close();
//    line.clear(); */
//
//    //  =================================================
//    // READ
//    //  =================================================
//
//    std::ifstream ClearText("/Users/sorohimm/CLionProjects/untitled2/cmake-build-debug/clearText.txt");
//    if (!ClearText.is_open()) {
//        std::cout << "ERROR!!! CAN NOT OPEN SCAN FILE" << std::endl;
//    }
//
//    vault mapa;
//    std::vector<std::string> words;
//    std::map<std::string, int> null;
//    while (!ClearText.eof()) {
//        getline(ClearText, line);
//        split(line, words);
//    }
//    for (size_t i = 0; i < words.size(); ++i) {
//        mapa[words[i]] = null;
//    }
//
//    std::vector<std::string> tmp;
//    while (!ClearText.eof()) {
//        getline(ClearText, line);
//        split(line, tmp);
//        for (auto i = tmp.begin(); i != tmp.end(); i++) {
//            if (i + 1 == tmp.end()) {
//                break;
//            }
//            if (mapa[*i].find(*(i + 1)) == mapa[*i].end()) {
//                mapa[*i].emplace(*i, 1);
//            } else {
//                ++mapa[*i][*(i + 1)];
//            }
//        }
//    }
//
//    //  =================================================
//    //  CUP OF CUM TO CUM FILE
//    //  =================================================
//
//    std::ofstream statTxt("statistic.txt");
//    if (!statTxt.is_open()) {
//        std::cout << "ERROR!!! CAN NOT OPEN OUTPUT FILE" << std::endl;
//    }
//    for (auto i = mapa.begin(); i != mapa.end(); ++i) {
//        statTxt << i->first << std::endl;
//        for (auto j = i->second.begin(); j != i->second.end(); ++j) {
//            statTxt << "             " << j->first << " " << j->second << std::endl;
//        }
//    }

    return 0;
}

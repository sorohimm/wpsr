//
// Copyright 2020 Vladimir Mashir
//

#include <header.h>

int main() {
    std::ifstream inputFile("../untitled2/text.txt");
    if (!inputFile.is_open()) { return 0; }

    std::ofstream outputFile("clearText.txt");
    if (!outputFile.is_open()) { return 0; }

    FormatFile(inputFile, outputFile);// delete all excess symbols
    outputFile.close();

    std::ifstream ClearText("../untitled2/cmake-build-debug/clearText.txt");
    if (!ClearText.is_open()) { return 0; }

    std::vector<std::string> WordsVector;
    FileToVector(ClearText, WordsVector);

    std::map<std::string, int> null;
    vault Statistics;
    for (const auto &word : WordsVector) {
        Statistics.emplace(word, null);
    }

    ClearText.clear();
    ClearText.seekg(0);// back to begin of the file

    MakeStatic(Statistics, ClearText);

    std::ofstream StatFile("statistic.txt");
    if (!StatFile.is_open()) { return 0; }

    MapOutput(Statistics, StatFile);// output map to dictionary

    return 0;
}

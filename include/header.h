//
// Created by sorohimm on 02.12.2020.
//

#ifndef UNTITLED2_HEADER_H
#define UNTITLED2_HEADER_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
//#include <boost/algorithm/string/join.hpp>
//#include <boost/algorithm/string/split.hpp>
//#include <boost/algorithm/string/classification.hpp>
//#include <boost/range/adaptor/transformed.hpp>

using vault = std::map<std::string, std::map<std::string, int>>;

void formatLine(std::string &input);
void split(const std::string &str, std::vector<std::string> &ans, char sep);
void MapOutput(const vault &input, std::ofstream &file);
void FileToVector(std::ifstream &InputFile, std::vector<std::string> &outputVector);
void FormatFile(std::ifstream &inputFile, std::ofstream &outputFile);
void MakeStatic(vault &Statistics, std::ifstream &ClearText);
void stringScan(std::string inputLine, std::vector<std::string> container);

#endif//UNTITLED2_HEADER_H

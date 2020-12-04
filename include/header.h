//
// Created by sorohimm on 02.12.2020.
//

#ifndef UNTITLED2_HEADER_H
#define UNTITLED2_HEADER_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/range/adaptor/transformed.hpp>





using vault = std::map<std::string, std::map<std::string, int>>;

void formatLine(std::string &input);
void split(const std::string& str, char sep);
void split(std::string& input, std::vector<std::string> container);
int deleteSingLet(std::string& input, int count);
void deleteSpaces(std::string& input);
void star(std::string& input);
void split(const std::string& str, std::vector<std::string> output,  char sep);
void substtr(const std::string &str, std::vector<std::string> output);
void splitt(const std::string& str, std::vector<std::string>& ans, char sep);

void stringScan(std::string inputLine, std::vector<std::string> container);





#endif //UNTITLED2_HEADER_H

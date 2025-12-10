#pragma once

#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;

class Tokenizer {
private:
    vector<string> tokens;
    size_t curTokenIdx; 

    void internalTokenize(const string& line, const string& delimiter);
public:
    Tokenizer(const string& inputString, const string & seperator = ",");
    string nextToken();
    bool hasMoreTokens() const;
    double nextDouble();
    int nextInt();
};
#include "Tokenizer.h"

void Tokenizer::internalTokenize(const string& line, const string& delimiter) {
    tokens.clear();
    curTokenIdx = 0;
    
    if (delimiter.empty()) {
        tokens.push_back(line);
        return;
    }

    size_t startPos = 0;
    size_t foundPos = line.find_first_of(delimiter, startPos);

    while (foundPos != string::npos) {
        size_t cnt = foundPos - startPos;
        string token = line.substr(startPos, cnt);

        if (!token.empty()) {
            tokens.push_back(token);
        }

        startPos = foundPos + 1;
        foundPos = line.find_first_of(delimiter, startPos);
    }

    size_t cnt = line.length() - startPos;
    if (cnt > 0) {
        string token = line.substr(startPos, cnt);
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
}

Tokenizer::Tokenizer(const string& inputString, const string& separator) {
    internalTokenize(inputString, separator);
}

string Tokenizer::nextToken() {
    if (curTokenIdx >= tokens.size()) return "";
    return tokens[curTokenIdx++];
}

bool Tokenizer::hasMoreTokens() const {
    return curTokenIdx < tokens.size();
}

double Tokenizer::nextDouble() {
    string token = nextToken();
    if (token.empty()) return 0.0;
    return stod(token);
}

int Tokenizer::nextInt() {
    string token = nextToken();
    if (token.empty()) return 0;
    return stoi(token);
}
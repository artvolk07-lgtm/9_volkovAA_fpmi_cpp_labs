#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

bool IsEmpty(std::ifstream& file) {
    return file.peek() == std::ifstream::traits_type::eof();
}

bool isRussianChar(unsigned char c) {
    if ((c >= 192 && c <= 223) || (c >= 224 && c <= 255) || c == 168 || c == 184) {
        return true;
    }
    return false;
}

unsigned char toLowerRussian(unsigned char c) {
    if (c >= 192 && c <= 223) {
        return c + 32;
    }
    if (c == 168) return 184;
    return std::tolower(c);
}

int findMaxSameCharLength(const std::string& str) {
    int maxLen = 0;
    int currentLen = 0;
    unsigned char currentChar = 0;

    for (size_t i = 0; i < str.length(); ++i) {
        unsigned char c = str[i];

        if (isRussianChar(c)) {
            unsigned char lowerC = toLowerRussian(c);

            if (i == 0 || lowerC != currentChar) {
                currentChar = lowerC;
                currentLen = 1;
            }
            else {
                currentLen++;
            }
            maxLen = std::max(maxLen, currentLen);
        }
        else {
            currentLen = 0;
            currentChar = 0;
        }
    }

    return maxLen;
}

int main() {
    std::setlocale(LC_ALL, ".1251");
    std::ifstream inputFile("input.txt");
       
    //std::cout << char(std::tolower('Ё'));


    if (!inputFile) {
        std::cout << "Не удалось открыть файл input.txt" << std::endl;
        return 1;
    }

    if (IsEmpty(inputFile)) {
        std::cout << "Ваш файл пустой!" << std::endl;
        return 1;
    }

    std::vector<std::pair<std::string, int>> linesWithMaxLen;
    int globalMaxLen = 0;
    std::string line;

    

    while (std::getline(inputFile, line)) {
        int maxLen = findMaxSameCharLength(line);

        if (maxLen > globalMaxLen) {
            globalMaxLen = maxLen;
            linesWithMaxLen.clear();
            linesWithMaxLen.push_back(std::make_pair(line, maxLen));
        }
        else if (maxLen == globalMaxLen && maxLen > 0) {
            linesWithMaxLen.push_back(std::make_pair(line, maxLen));
        }
    }

    inputFile.close();

    if (globalMaxLen == 0) {
        std::cout << "В файле не найдено русских букв, идущих подряд" << std::endl;
        return 0;
    }

    std::cout << "Максимальная длина подстроки из одинаковых русских букв: "
        << globalMaxLen << std::endl;
    std::cout << "Найдено строк: " << linesWithMaxLen.size() << std::endl;
    std::cout << "==========================================" << std::endl;
    
    int limit = std::min(10, static_cast<int>(linesWithMaxLen.size()));
    for (int i = 0; i < limit; ++i) {
        std::cout << "Строка " << (i + 1) << " (длина повтора: "
            << linesWithMaxLen[i].second << "):" << std::endl;
        std::cout << linesWithMaxLen[i].first << std::endl;
        std::cout << "------------------------------------------" << std::endl;
    }

    if (linesWithMaxLen.size() > 10) {
        std::cout << "... и еще " << (linesWithMaxLen.size() - 10)
            << " строк" << std::endl;
    }

    return 0;
}
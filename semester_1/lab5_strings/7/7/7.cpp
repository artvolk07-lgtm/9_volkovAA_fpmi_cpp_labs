#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <windows.h>

bool isAllDigits(const std::string& word) {
    if (word.empty()) return false;
    for (char c : word) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

std::string findAndMovePreLastMaxNumber(std::string input) {
    std::vector<std::string> words;
    std::vector<std::string> numberWords;

    std::stringstream ss(input);
    std::string word;

    while (ss >> word) {
        words.push_back(word);
        if (isAllDigits(word)) {
            numberWords.push_back(word);
        }
    }

    if (numberWords.empty()) {
        return input;
    }

    std::string maxNumber = numberWords[0];
    for (size_t i = 1; i < numberWords.size(); i++) {
        if (numberWords[i].length() > maxNumber.length() ||
            (numberWords[i].length() == maxNumber.length() && numberWords[i] > maxNumber)) {
            maxNumber = numberWords[i];
        }
    }

    std::vector<int> maxPositions;
    for (int i = 0; i < words.size(); i++) {
        if (isAllDigits(words[i]) && words[i] == maxNumber) {
            maxPositions.push_back(i);
        }
    }

    int targetPosition;
    if (maxPositions.size() == 1) {
        targetPosition = maxPositions[0];
    }
    else {
        targetPosition = maxPositions[maxPositions.size() - 2];
    }

    std::string targetNumber = words[targetPosition];

    std::string result;

    result += targetNumber;
    result += " ";

    for (int i = 0; i < words.size(); i++) {
        if (i == targetPosition) {
            continue;
        }
        result += words[i];
        result += " ";
    }

    if (!result.empty()) {
        result.pop_back();
    }

    return result;
}

int main() {

    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::cout << "Original: " << input << std::endl;

    std::string result = findAndMovePreLastMaxNumber(input);
    std::cout << "Modified: " << result << std::endl;

    return 0;
}
#include <iostream>
#include <limits>

int main() {

    setlocale(LC_ALL, "RU");
    const int n = 10;
    double numbers[n];

    std::cout << "Введи 10 вещественных чисел:" << std::endl;

    for (int i = 0; i < n; i++) {
        while (true) {
            std::cout << "Число " << (i + 1) << ": ";
            std::cin >> numbers[i];

            if (std::cin.fail()) {
                
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Шизик? Я сказал число!!" << std::endl;
            }
            else {
               
                break;
            }
        }
    }

    int count = 0;

    
    for (int i = 1; i < n - 1; i++) {
        if (numbers[i] < numbers[i - 1] && numbers[i] < numbers[i + 1]) {
            count++;
        }
    }

    std::cout << "Количество чисел, меньших своих соседей: " << count << std::endl;

    return 0;
}


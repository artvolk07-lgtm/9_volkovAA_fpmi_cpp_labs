#include <iostream>


int main()
{
    const int n = 10;
    double numbers[n];

    std::cout << "Vvedi 10 chisel: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    int C = 0;

    for (int i = 1; i < n - 1; i++) {
        if (numbers[i] < numbers[i - 1] && numbers[i] < numbers[i + 1]) {
            C++;
        }
    }

    std::cout << "Kol vo < sosedei: " << C << std::endl;

    return 0;
}


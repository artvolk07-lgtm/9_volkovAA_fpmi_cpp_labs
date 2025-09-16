
#include <iostream>

int main()
{
    int n;
    std::cout << "Vvedi kol vo nech chisel: " ;
    std::cin >> n ;
    std::cout << std::endl;

    if (n < 0  || std::cin.fail()) {
        std::cout << "opiat ti tupik? Kol vo POLOSHITELNOE CHISLO";
        std::cout << std::endl;
        return 1;
    }
    int S = n * n; 
    std::cout << "summa pervih" << n << "nech chisel: " << S << std::endl;
    return 0;
}


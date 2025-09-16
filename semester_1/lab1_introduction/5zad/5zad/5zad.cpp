#include <iostream>
#include <cmath>
int main()
{
    int  n, m;

    std::cout << "Vvedite n: ";
    std::cin >> n;
    std::cout << "Vvedite m: ";
    std::cin >> m;

    n = std::abs(n);
    m = std::abs(m);

    std::cout << "obsh del: ";

    int min = (n < m) ? n : m;

    for (int i = 1; i <= min; i++) {

        if (n % i == 0 && m % i == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;

}

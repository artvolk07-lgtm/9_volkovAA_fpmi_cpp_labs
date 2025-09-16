/* if (m || std::cin.fail()) {
       std::cout << std::endl;
       std::cout << "Nu ya sh chislo prosil";
       std::cout << std::endl;
       return 1;
   } */
#include <iostream>

int main() {
    int n;
    std::cout << "ya naidu summu chet i proisv nech na otreske: "<< std::endl;
    std::cin >> n;

    long sum_even = 0;
    long product_odd = 1;

    if (n > 0) {
        
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum_even += i;
            }
            else {
                product_odd *= i;
            }
        }
    }
    else {
        for (int i = n; i <= 1; i++) {
            if (i % 2 == 0) {
                sum_even += i;
            }
            else {
                product_odd *= i;
            }
        }
    }


    std::cout << "summa: " << sum_even << std::endl;
    std::cout << "proisv:  " << product_odd << std::endl;

    return 0;
}

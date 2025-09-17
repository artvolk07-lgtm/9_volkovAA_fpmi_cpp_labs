#include <iostream>
#include <cmath>
#include <limits>

int main()
{
    int  n;

    
    
    bool N = false;
    while (!N) {
        std::cout << "Vvedite n: ";

        std::cin >> n;
        std::cout << std::endl;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Poprobui eshe ras:  " << std::endl;
            std::cout << std::endl;
        }
        else {
            if (n == 0) {
                std::cout << "Vvedite naturalnoe chislo (bolshe 0): " << std::endl;
                std::cout << std::endl;
            }
            else {
                N = true;

            }
        
            
        }
    }

    int m;

    bool M = false;
    while (!M) {
        std::cout << "Vvedite m: ";

        std::cin >> m;
        std::cout << std::endl;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Poprobui eshe ras:  " << std::endl;
            std::cout << std::endl;
        }
        else {
            if(m == 0) {
                std::cout << "Vvedite naturalnoe chislo (bolshe 0): " << std::endl;
                std::cout << std::endl;
            }
            else {
                M = true;
               
            }
        }
    }
    
   
    
    n = std::abs(n);
    m = std::abs(m);

    std::cout << "obsh del: ";

   /* if (m || std::cin.fail()) {
        std::cout << std::endl;
        std::cout << "Nu ya sh chislo prosil";
        std::cout << std::endl;
        return 1;
    } */

    int min = (n < m) ? n : m;

    for (int i = 1; i <= min; i++) {

        if (n % i == 0 && m % i == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;

}

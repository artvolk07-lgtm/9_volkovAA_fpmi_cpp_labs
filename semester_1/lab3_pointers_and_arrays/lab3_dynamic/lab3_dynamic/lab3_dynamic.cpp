#include <iostream>
#include <random>
#include <cmath>

int main() {
    int n = 0;
    const int MAXSIZE = 100;
    std::cout << "Enter the number array elements (not more than 100):\n";
    if (!(std::cin >> n)) {
        std::cout << "natural numbers only";
        std::exit(1);
    }
    if (n > MAXSIZE) {
        std::cout << " size limit exceeded.please enter a number less than 100";
        std::exit(1);
    }
    int* arr = new int[n];

    int choice;
    std::cout << "Choose array filling method:" << std::endl;
    std::cout << "1 - Manual input" << std::endl;
    std::cout << "2 - Random numbers" << std::endl;
    std::cin >> choice;

    if (choice == 1) {
   
        std::cout << "Enter " << n << " array elements:" << std::endl;
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
            if (std::cin.fail()) {
                std::cout << "Error: Invalid input. Please enter integers only." << std::endl;
                delete[] arr;
                return 1;
            }
        }
    }
    else if (choice == 2) {
      
        int a, b;
        std::cout << "Enter interval boundaries [a, b]: ";
        std::cin >> a >> b;

        if (a > b) {
            std::cout << "Error: a must be less than or equal to b." << std::endl;
            delete[] arr;
            return 1;
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(a, b);

        for (int i = 0; i < n; ++i) {
            arr[i] = dist(gen);
        }
    }
    else {
        std::cout << "Invalid choice." << std::endl;
        delete[] arr;
        return 1;
    }


    std::cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

 
    int oddSum = 0;
    for (int i = 1; i < n; i += 2) {
        oddSum += arr[i];
    }
    std::cout << "1. Sum of elements with odd indices: " << oddSum << std::endl;

    int firstPos = -1, lastPos = -1;

 
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            firstPos = i;
            break;
        }
    }


    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] > 0) {
            lastPos = i;
            break;
        }
    }

    int product = 0;
    if (firstPos != -1 && lastPos != -1 && firstPos < lastPos - 1) {
        product = 1;
        for (int i = firstPos + 1; i < lastPos; ++i) {
            product *= arr[i];
        }
    }
    std::cout << "2. Product between first and last positive elements: " << product << std::endl;

    
    int N;
    std::cout << "Enter number N for compression: ";
    std::cin >> N;

    int writeIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (std::abs(arr[i]) <= N) {
            arr[writeIndex] = arr[i];
            writeIndex++;
        }
    }

    for (int i = writeIndex; i < n; ++i) {
        arr[i] = 0;
    }

    std::cout << "3. Compressed array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;
}
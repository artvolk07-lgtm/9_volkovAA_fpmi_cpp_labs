#include <iostream>
#include <random>
#include <cmath>

const int MAXSIZE = 100;

int getArraySize() {
    int n = 0;
    std::cout << "Enter the number array elements (not more than 100):\n";

    if (!(std::cin >> n)) {
        std::cout << "natural numbers only";
        std::exit(1);
    }

    if (n > MAXSIZE) {
        std::cout << " size limit exceeded.please enter a number less than 100";
        std::exit(1);
    }

    return n;
}

void manualInput(int* arr, int n) {
    std::cout << "Enter " << n << " array elements:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        if (std::cin.fail()) {
            std::cout << "Error: Invalid input. Please enter integers only." << std::endl;
            throw std::runtime_error("Invalid input");
        }
    }
}

void randomInput(int* arr, int n) {
    int a, b;
    std::cout << "Enter interval boundaries [a, b]: ";
    std::cin >> a >> b;

    if (a > b) {
        std::cout << "Error: a must be less than or equal to b." << std::endl;
        throw std::runtime_error("Invalid interval");
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(a, b);

    for (int i = 0; i < n; ++i) {
        arr[i] = dist(gen);
    }
}

void fillArray(int* arr, int n) {
    int choice;
    std::cout << "Choose array filling method:" << std::endl;
    std::cout << "1 - Manual input" << std::endl;
    std::cout << "2 - Random numbers" << std::endl;
    std::cin >> choice;

    if (choice == 1) {
        manualInput(arr, n);
    }
    else if (choice == 2) {
        randomInput(arr, n);
    }
    else {
        std::cout << "Invalid choice." << std::endl;
        throw std::runtime_error("Invalid choice");
    }
}

void printArray(const int* arr, int n, const std::string& message = "Array: ") {
    std::cout << message;
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int calculateOddIndexSum(const int* arr, int n) {
    int oddSum = 0;
    for (int i = 1; i < n; i += 2) {
        oddSum += arr[i];
    }
    return oddSum;
}

int findFirstPositiveIndex(const int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            return i;
        }
    }
    return -1;
}

int findLastPositiveIndex(const int* arr, int n) {
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] > 0) {
            return i;
        }
    }
    return -1;
}

int calculateProductBetweenPositives(const int* arr, int n) {
    int firstPos = findFirstPositiveIndex(arr, n);
    int lastPos = findLastPositiveIndex(arr, n);

    int product = 0;
    if (firstPos != -1 && lastPos != -1 && firstPos < lastPos - 1) {
        product = 1;
        for (int i = firstPos + 1; i < lastPos; ++i) {
            product *= arr[i];
        }
    }
    return product;
}

void compressArray(int* arr, int n, int N) {
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
}

int main() {
    try {
        int n = getArraySize();

        int* arr = new int[n];

        fillArray(arr, n);

        printArray(arr, n, "Original array: ");

       
        int oddSum = calculateOddIndexSum(arr, n);
        std::cout << "1. Sum of elements with odd indices: " << oddSum << std::endl;

      
        int product = calculateProductBetweenPositives(arr, n);
        std::cout << "2. Product between first and last positive elements: " << product << std::endl;

      
        int N;
        std::cout << "Enter number N for compression: ";
        std::cin >> N;

        compressArray(arr, n, N);
        printArray(arr, n, "3. Compressed array: ");

     
        delete[] arr;

    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
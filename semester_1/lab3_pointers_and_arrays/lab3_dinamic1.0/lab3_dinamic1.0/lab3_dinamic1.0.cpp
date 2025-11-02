#include <iostream>
#include <random>
#include <cmath>

void fillManual(int arr[], int n) {
    std::cout << "Enter " << n << " array elements:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        if (std::cin.fail()) {
            std::cout << "Error: Invalid input. Please enter integers only." << std::endl;
            delete[] arr;

        }
    }
}

void fillRandom(int arr[], int n) {
    int a, b;
    std::cout << "Enter interval boundaries [a, b]: ";
    std::cin >> a >> b;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(a, b);

    for (int i = 0; i < n; i++) {
        arr[i] = dist(gen);
    }
}

void printArray(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i < n - 1) std::cout << ", ";
    }
    ;
}

int sumOddIndices(int arr[], int n) {
    int sum = 0;
    for (int i = 1; i < n; i += 2) {
        sum += arr[i];
    }
    return sum;
}

int productBetweenPositives(int arr[], int n) {
    int firstPos = -1, lastPos = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            firstPos = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > 0) {
            lastPos = i;
            break;
        }
    }

    if (firstPos == -1 || lastPos == -1 || firstPos >= lastPos) {
        return 0;
    }

    int product = 1;
    for (int i = firstPos + 1; i < lastPos; i++) {
        product *= arr[i];
    }

    return product;
}

void compressArray(int arr[], int n, int N) {
    int writeIndex = 0;

    for (int i = 0; i < n; i++) {
        if (std::abs(arr[i]) <= N) {
            arr[writeIndex] = arr[i];
            writeIndex++;
        }
    }

    for (int i = writeIndex; i < n; i++) {
        arr[i] = 0;
    }
}

int main() {
    int n, choice, N;      

    std::cout << "Enter array size: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Array size must be positive!\n";
        return 1;
    }

    int* arr = new int[n];

    std::cout << "\nChoose array filling method:\n";
    std::cout << "1 - Manual input\n";
    std::cout << "2 - Random numbers\n";
    std::cin >> choice;

    switch (choice) {
    case 1:
        fillManual(arr, n);
        break;
    case 2:
        fillRandom(arr, n);
        break;
    default:
        std::cout << "Invalid choice!\n";
        delete[] arr;
        return 1;
    }

    std::cout << "\nOrig: ";
    printArray(arr, n);

    int sumOdd = sumOddIndices(arr, n);
    std::cout << "\n1. Sum of elements with odd indices: " << sumOdd << std::endl;

    int product = productBetweenPositives(arr, n);
    std::cout << "2. Product between first and last positive elements: " << product << std::endl;

    std::cout << "\nEnter number N for array compression: ";
    std::cin >> N;

    compressArray(arr, n, N);
    std::cout << "Compressed array: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}
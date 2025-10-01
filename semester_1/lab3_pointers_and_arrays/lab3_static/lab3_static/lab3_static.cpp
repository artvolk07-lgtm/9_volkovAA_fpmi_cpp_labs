#include <iostream>
#include <random>
#include <cmath>
#include <algorithm>
#include <limits>

const int MAX_SIZE = 100;

void fillArrayManually(double arr[], int n) {
    std::cout << "Enter " << n << " array elements:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        if (std::cin.fail()) {
            std::cout << "Error: Invalid input. Please enter numbers only.\n";
            exit(1);
        }
    }
}

void fillArrayRandomly(double arr[], int n, double a, double b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(a, b);
    for (int i = 0; i < n; ++i) {
        arr[i] = dist(gen);
    }
}

double findMaxAbsolute(double arr[], int n) {
    double maxAbs = std::abs(arr[0]);
    for (int i = 1; i < n; ++i) {
        if (std::abs(arr[i]) > maxAbs) {
            maxAbs = std::abs(arr[i]);
        }
    }
    return maxAbs;
}

double sumBetweenPositives(double arr[], int n) {
    int firstPos = -1, secondPos = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            if (firstPos == -1) {
                firstPos = i;
            }
            else {
                secondPos = i;
                break;
            }
        }
    }
    if (firstPos == -1 || secondPos == -1 || secondPos - firstPos <= 1) {
        return 0;
    }
    double sum = 0;
    for (int i = firstPos + 1; i < secondPos; ++i) {
        sum += arr[i];
    }
    return sum;
}

void sortByFrequency(double arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            int freq1 = 0;
            for (int k = 0; k < n; ++k) {
                if (arr[k] == arr[j]) {
                    freq1++;
                }
            }
            int freq2 = 0;
            for (int k = 0; k < n; ++k) {
                if (arr[k] == arr[j + 1]) {
                    freq2++;
                }
            }
            if (freq1 < freq2 || (freq1 == freq2 && arr[j] > arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(double arr[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    double arr[MAX_SIZE];
    int n;

    std::cout << "Enter the number of array elements (no more than " << MAX_SIZE << "): ";
    std::cin >> n;

    if (std::cin.fail() || n <= 0 || n > MAX_SIZE) {
        std::cout << "Error: Invalid array size!\n";
        return 1;
    }

    int choice;
    std::cout << "Choose array filling method:\n";
    std::cout << "1 - Manual input\n";
    std::cout << "2 - Random numbers\n";
    std::cin >> choice;

    if (choice == 1) {
        fillArrayManually(arr, n);
    }
    else if (choice == 2) {
        double a, b;
        std::cout << "Enter interval boundaries [a, b]: ";
        std::cin >> a >> b;
        if (a > b) {
            std::cout << "Error: a must be less than or equal to b!\n";
            return 1;
        }
        fillArrayRandomly(arr, n, a, b);
    }
    else {
        std::cout << "Invalid choice!\n";
        return 1;
    }

    std::cout << "Original array: ";
    printArray(arr, n);

    double maxAbs = findMaxAbsolute(arr, n);
    std::cout << "1. Maximum absolute element: " << maxAbs << std::endl;

    double sum = sumBetweenPositives(arr, n);
    std::cout << "2. Sum between first and second positive elements: " << sum << std::endl;

    sortByFrequency(arr, n);
    std::cout << "3. Array sorted by frequency (descending): ";
    printArray(arr, n);

    return 0;
}
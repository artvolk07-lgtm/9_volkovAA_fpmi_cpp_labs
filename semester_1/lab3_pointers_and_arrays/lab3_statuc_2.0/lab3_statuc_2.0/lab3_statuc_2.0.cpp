#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>

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
    double* q = new double[n];
    int choice;
    std::cout << "Choose array filling method:\n";
    std::cout << "1 - Manual input\n";
    std::cout << "2 - Random numbers\n";
    std::cin >> choice;

    

    if (choice == 2) {
        double a = 0;
        double b = 0;
        std::cout << "Enter interval boundaries [a, b]:" << std::endl;
        if (!(std::cin >> a >> b)) {
            std::cout << "Error. Enter numbers please and a must be less than or equal to b.";
            delete[] q;
            std::exit(1);
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(a, b);
        for (int i = 0; i < n; ++i) {
            q[i] = dist(gen);
            std::cout << q[i] << " ";
        }
    }

    

    else if (choice == 1) {
        std::cout << "Enter " << n << " array elements:" << std::endl;
        for (int i = 0; i < n; ++i) {
            if (!(std::cin >> q[i])) {
                std::cout << "Couldnt read.Enter whole numbers";
                delete[] q;
                std::exit(1);
            }

        }
    }

    else {
        std::cout << "Invalid choice." << std::endl;
        delete[] q;
        return 1;
    }


    double maxAbs = std::abs(q[0]);
    for (int i = 1; i < n; ++i) {
        if (std::abs(q[i]) > maxAbs) {
            maxAbs = std::abs(q[i]);
        }
    }
    std::cout << "the biggest absolute number is :" << maxAbs << std::endl;
    int firstPos = 0, secondPos = 0;
    int positivecount = 0;
    for (int i = 0; i < n; ++i) {
        if (q[i] > 0) {
            positivecount++;
            if (positivecount == 1) {
                firstPos = i;
            }
            else if (positivecount == 2) {
                secondPos = i;
                break;
            }
        }
    }
    double sum = 0;
    int start = std::min(firstPos, secondPos);
    int end = std::max(firstPos, secondPos);
    if (firstPos != -1 && secondPos != -1) {
        for (int i = start + 1; i < end; ++i) {
            sum += q[i];
        }
    }
    if (sum == 0) {
        std::cout << "positive elements are right to each other or the sum is 0" << std::endl;
    }
    else {
        std::cout << "the sum equals to:" << sum << std::endl;
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            int freq1 = 0;
            for (int k = 0; k < n; ++k) {
                if (q[k] == q[j]) {
                    freq1++;
                }
            }
            int freq2 = 0;
            for (int k = 0; k < n; ++k) {
                if (q[k] == q[j + 1]) {
                    freq2++;
                }
            }
            if (freq1 < freq2 || (freq1 == freq2 && q[j] > q[j + 1])) {
                std::swap(q[j], q[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << q[i] << " ";
    }
    std::cout << std::endl;

}
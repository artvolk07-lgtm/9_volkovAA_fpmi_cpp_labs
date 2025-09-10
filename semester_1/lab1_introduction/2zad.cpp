#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long sum_even = 0;
    long long product_odd = 1;

    for (int i = 1; i <= n; i++) { 
        if (i % 2 == 0) {
            sum_even += i;
        }
        else {
            product_odd *= i;
        }
    }

    cout << sum_even << " " << product_odd << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int a, b, d;
    cin >> a >> b >> d;

    if (a > b) {
        return 0;
    }

    if (d == 0) {
        if (a % 3 == 0) {
            cout << a << endl;
        }
    }
    else if (d > 0) {
        int n_max = (b - a) / d;
        for (int n = 0; n <= n_max; n++) {
            int term = a + n * d;
            if (term > b) break;
            if (term % 3 == 0) {
                cout << term << endl;
            }
        }
    }
    else {
        if (a % 3 == 0) {
            cout << a << endl;
        }
    }

    return 0;
}


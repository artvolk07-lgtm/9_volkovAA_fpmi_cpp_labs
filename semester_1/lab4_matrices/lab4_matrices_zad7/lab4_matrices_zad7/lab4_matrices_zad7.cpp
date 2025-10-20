#include <iostream>
#include <random>
#include <iomanip>

void fillSM(int** matrix, int n) {
	int val = 1;
	int top = 0, bot = n - 1, left = 0, right = n - 1;


	while (top <= bot && left <= right) {

		for (int i = left; i <= right; i++) {
			matrix[top][i] = val++;
		}

		top++;

		for (int i = top; i <= bot; i++) {
			matrix[i][right] = val++;
		}
		right--;

		if (top <= bot) {
			for (int i = right; i >= left; i--) {
				matrix[bot][i] = val++;
			}
			bot--;
		}
        if (left <= right) {
            for (int i = bot; i >= top; i--) {
                matrix[i][left] = val++;
            }
            left++;
        }
    }
}

void printM(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(4) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int sumSecondaryDiagonal(int** matrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][n - 1 - i];
    }
    return sum;
}




void fillMatrix(int** matrix, int n) {
    
        fillSM(matrix, n);
    
}

int main() {
    try {
        int n;
        std::cout << "Enter matrix size n (for n x n matrix): ";
        std::cin >> n;

        if (n <= 0) {
            std::cout << "Error: Matrix size must be positive." << std::endl;
            return 1;
        }

        int** matrix = new int* [n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
        }

        
        fillMatrix(matrix, n);

        
        std::cout << "\nMatrix " << n << "x" << n << ":" << std::endl;
        printM(matrix, n);

        int diagonalSum = sumSecondaryDiagonal(matrix, n);
        std::cout << "\nSum of secondary diagonal: " << diagonalSum << std::endl;

        std::cout << "Secondary diagonal elements: ";
        for (int i = 0; i < n; i++) {
            std::cout << matrix[i][n - 1 - i];
            if (i < n - 1) std::cout << " + ";
        }
        std::cout << " = " << diagonalSum << std::endl;

        for (int i = 0; i < n; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

	

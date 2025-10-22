#include <iostream>
#include <random>
#include <iomanip>
#include <ctime>
#include <cstdlib>

void bubble_sort(int* arr, int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            bool condition = ascending ? (arr[j] > arr[j + 1]) : (arr[j] < arr[j + 1]);
            if (condition) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void counting_sort(int* arr, int size, bool ascending) { //мин макс, заполняем массив подсчета, сорт массив
    if (size == 0) return;


    int min_val = arr[0], max_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) min_val = arr[i];
        if (arr[i] > max_val) max_val = arr[i];
    }
    int range = max_val - min_val + 1;
    int* count = new int[range]();

    
    for (int i = 0; i < size; i++) {
        count[arr[i] - min_val]++;
    }

    
    int index = 0;
    if (ascending) {
        for (int i = 0; i < range; i++) {
            while (count[i] > 0) {
                arr[index++] = i + min_val;
                count[i]--;
            }
        }
    }
    else {
        for (int i = range - 1; i >= 0; i--) {
            while (count[i] > 0) {
                arr[index++] = i + min_val;
                count[i]--;
            }
        }
    }

    delete[] count;
}

void quick_sort_recursive(int* arr, int left, int right, bool ascending) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        if (ascending) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
        }
        else {
            while (arr[i] > pivot) i++;
            while (arr[j] < pivot) j--;
        }

        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    quick_sort_recursive(arr, left, j, ascending);
    quick_sort_recursive(arr, i, right, ascending);
}

void quick_sort(int* arr, int size, bool ascending) {
    quick_sort_recursive(arr, 0, size - 1, ascending);
}




bool camper(int first_number, int second_number) {
    return first_number > second_number;
}

void input_sides(int& n, int& m) {
    std::cout << "Enther rows: ";
    if (!(std::cin >> n) &&  n < 1) {
        std::cout << "Fail. Natural only";
        std::exit(1);
    }
    std::cout << "\nEnter columns: ";
    if (!(std::cin >> m) && m < 1) {
        std::cout << "Fail. Natural only";
        std::exit(1);
    }
}
void merge(int* arr, int left, int mid, int right, bool ascending) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* left_arr = new int[n1];
    int* right_arr = new int[n2];

    for (int i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        right_arr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        bool condition = ascending ? (left_arr[i] <= right_arr[j]) : (left_arr[i] >= right_arr[j]);
        if (condition) {
            arr[k] = left_arr[i];
            i++;
        }
        else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }

    delete[] left_arr;
    delete[] right_arr;
}

void merge_sort_recursive(int* arr, int left, int right, bool ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort_recursive(arr, left, mid, ascending);
        merge_sort_recursive(arr, mid + 1, right, ascending);

        merge(arr, left, mid, right, ascending);
    }
}

void merge_sort(int* arr, int size, bool ascending) {
    merge_sort_recursive(arr, 0, size - 1, ascending);
}

void insertion_sort(int* arr, int size, bool ascending) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        if (ascending) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        else {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int* arr, int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        int extreme_index = i;
        for (int j = i + 1; j < size; j++) {
            bool condition = ascending ? (arr[j] < arr[extreme_index]) : (arr[j] > arr[extreme_index]);
            if (condition) {
                extreme_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[extreme_index];
        arr[extreme_index] = temp;
    }
}


void print_matrix(int** matrix, int rows, int cols) {
    std::cout << "\nMatrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void creating_matrices(int**& matrices, int n, int m) {
    matrices = new int* [n];
    for (int i = 0; i < n; i++) {
        matrices[i] = new int[m];
    }
}

void Random(int** matr, int n, int m) {
    int lower, upper;
    std::cout << "Enter boundaries: ";
    if (!(std::cin >> lower >> upper)) {
        std::cout << "Fail. Natural only";
        std::exit(1);
    }

    if (lower > upper) {
        std::swap(lower, upper);
    }

    std::mt19937 gen(45218965);
    std::uniform_int_distribution<int> dist(lower, upper);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matr[i][j] = dist(gen);
        }
    }
}

void Manual(int** matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!(std::cin >> matr[i][j])) {
                std::cout << "Fail. follow the instruction!";
                std::exit(1);
            }
        }
    }
}

void sort_matrix(int** matrix, int rows, int cols, int sort_method, bool ascending) {
    int total_size = rows * cols;
    int* flat_array = new int[total_size];

    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            flat_array[index++] = matrix[i][j];
        }
    }

    switch (sort_method) {
    case 1:
        bubble_sort(flat_array, total_size, ascending);
        break;
    case 2:
        counting_sort(flat_array, total_size, ascending);
        break;
    case 3:
        quick_sort(flat_array, total_size, ascending);
        break;
    case 4:
        merge_sort(flat_array, total_size, ascending);
        break;
    case 5:
        insertion_sort(flat_array, total_size, ascending);
        break;
    case 6:
        selection_sort(flat_array, total_size, ascending);
        break;
    }

    index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = flat_array[index++];
        }
    }

    delete[] flat_array;
}

int main() {
    int rows, cols;
    int input_choice, sort_choice, order_choice;

    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    
    std::cout << "Choose input method:\n";
    std::cout << "1 - Manual input\n";
    std::cout << "2 - Random numbers\n";
    std::cout << "Your choice: ";
    std::cin >> input_choice;

    if (input_choice == 1) {
        Manual(matrix, rows, cols);
    }
    else {
        Random(matrix, rows, cols);
    }

    
    std::cout << "\n Orriginal:";
    print_matrix(matrix, rows, cols);

    
    

    std::cout << "Type of sort: \n";
    std::cout << "1 - Bubble sort\n";
    std::cout << "2 - Counting sort\n";
    std::cout << "3 - Quicksort\n";
    std::cout << "4 - Merge sort\n";
    std::cout << "5 - Input sort\n";
    std::cout << "6 - Choise sort\n";
    if (!(std::cin >> sort_choice)) {
        std::cout << " 1 - 6 ";
    }

    
    std::cout << "\nChoose sorting order:\n";
    std::cout << "1 - Increase\n";
    std::cout << "2 - Decrease\n";
    std::cout << "Your choice: ";
    std::cin >> order_choice;

    bool ascending = (order_choice == 1);

    
    sort_matrix(matrix, rows, cols, sort_choice, ascending);

    std::cout << "\nSorted matrix:";
    print_matrix(matrix, rows, cols);

    
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;

}
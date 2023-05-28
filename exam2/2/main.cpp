/* Создать два динамических массива А, В (одномерный, целочисленный). Размер массива А задается пользователем с клавиатуры (не более 20 элементов).
 * Память под массив А и В выделяется с использованием функции new.
 * Массив А заполняется числами с клавиатуры.
 * В массив В перенести все элементы массива А,
 * стоящие левее минимального элемента и имеющие нечетный индекс.
 * Массив В отсортировать по убыванию методом пузырька.
 * Реализовать с помощью функции алгоритм сортировки. Вывести на экран массив А и В.
Формат ввода
 10
1 2 3 4 2 3 4 9 1 7
Формат вывода
1 2 3 4 2 3 4 9 1 7
9 4 3 2
 */

#include <iostream>

using namespace std;

struct Min_values {
    int i;
    int min;
    int how_many_symbols;
};

Min_values find_min_index(int *A, int n) {
    Min_values min_values;
    min_values.i = 0;
    min_values.min = A[0];
    min_values.how_many_symbols = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] <= min_values.min) {
            min_values.min = A[i];
            min_values.i = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i < min_values.i and i % 2 != 0) min_values.how_many_symbols++;
    }
    return min_values;
}

void fill_final_array_and_sort(int const *A, int *B, Min_values minValues) {
    int j = 0;
    for (int i = 0; i < minValues.i; ++i) {
        if (i < minValues.i and i % 2 != 0) {
            B[j] = A[i];
            j++;
        }
    }

    int tmp;
    for (int j = 0; j < minValues.how_many_symbols; j++) {
        for (int i = 0; i <= minValues.how_many_symbols; i++) {
            if (B[i] < B[i + 1] and i <= minValues.i) {
                tmp = B[i];
                B[i] = B[i + 1];
                B[i + 1] = tmp;
            }
        }
    }
}

int main() {

    int n;

    cout << "Enter n:\n";
    cin >> n;

    if (n > 20 or n < 0) return 1;

    int *A = new int[n];

    cout << "Enter A array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    Min_values min_values;

    min_values = find_min_index(A, n);
    int *B = new int[min_values.how_many_symbols];
    fill_final_array_and_sort(A, B, min_values);

    cout << "Result of A array:\n";
    for (int i = 0; i < n; ++i) {
        cout << A[i]<<" ";
    }
    cout << "\nResult of B array:\n";
    for (int i = 0; i < min_values.how_many_symbols; ++i) {
        cout << B[i] << " ";

    }

    return 0;
}

#include "my_array_library.h"
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Dizideki deðeri arama
void search_value(int **array, int rows, int cols, int value, int **result, int *result_count) {
    // Öncelikle kaç tane eþleþme olduðunu hesaplayalým
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] == value) {
                count++;
            }
        }
    }

    // Eþleþmeler için bellekte dinamik olarak yer ayýralým
    *result = (int *)malloc(2 * count * sizeof(int));
    *result_count = count;

    // Eþleþmelerin indekslerini result dizisine atayalým
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] == value) {
                (*result)[index++] = i;
                (*result)[index++] = j;
            }
        }
    }
}
// Tekrarlanmayan eleman sayýsýný bulma
int* find_non_repeated_elements(int **array, int rows, int cols, int *non_repeated_count) {
    int *non_repeated_elements = (int *)malloc(rows * cols * sizeof(int)); // Maksimum eleman sayýsý kadar yer ayýrýyoruz
    *non_repeated_count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            bool is_unique = true;
            for (int k = 0; k < rows; k++) {
                for (int l = 0; l < cols; l++) {
                    if ((i != k || j != l) && array[i][j] == array[k][l]) {
                        is_unique = false;
                        break;
                    }
                }
                if (!is_unique) break;
            }
            if (is_unique) {
                non_repeated_elements[*non_repeated_count] = array[i][j];
                (*non_repeated_count)++;
            }
        }
    }
    // Belleði yeniden boyutlandýrýn, böylece yalnýzca tekrarlanmayan elemanlarý saklayacak kadar yer kullanýlýr
    non_repeated_elements = (int *)realloc(non_repeated_elements, (*non_repeated_count) * sizeof(int));
    return non_repeated_elements;
}

// Dizinin minimum elemanýný bulma
int find_min_element(int **array, int rows, int cols) {
    int min = INT_MAX;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] < min) {
                min = array[i][j];
            }
        }
    }
    return min;
}

// Her satýrýn maksimum elemanýný bulma
void find_max_elements_each_row(int **array, int rows, int cols, int *max_elements) {
    for (int i = 0; i < rows; i++) {
        int max = INT_MIN;
        for (int j = 0; j < cols; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
        max_elements[i] = max;
    }
}

// Satýrlarý azalan sýrada bubble sort ile sýralama
void sort_rows_descending(int **array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            for (int k = 0; k < cols - j - 1; k++) {
                if (array[i][k] < array[i][k + 1]) {
                    int temp = array[i][k];
                    array[i][k] = array[i][k + 1];
                    array[i][k + 1] = temp;
                }
            }
        }
    }
}

// Matrisin transpozunu bulma
void transpose_matrix(int **array, int rows, int cols, int **result) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = array[i][j];
        }
    }
}

// Ýki matrisi çarpma
void multiply_matrices(int **array1, int **array2, int size, int **result) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }
}


// Kimlik matrisi olup olmadýðýný kontrol etme
bool is_identity_matrix(int **array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j && array[i][j] != 1) return false;
            if (i != j && array[i][j] != 0) return false;
        }
    }
    return true;
}

// Simetrik matrisi olup olmadýðýný kontrol etme
bool is_symmetric_matrix(int **array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i][j] != array[j][i]) return false;
        }
    }
    return true;
}

void LUdecomposition(double A[N][N], double L[N][N], double U[N][N]) {
    for (int i = 0; i < N; i++) {
        // Upper Triangular
        for (int k = i; k < N; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += (L[i][j] * U[j][k]);
            U[i][k] = A[i][k] - sum;
        }
        // Lower Triangular
        for (int k = i; k < N; k++) {
            if (i == k)
                L[i][i] = 1;
            else {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (L[k][j] * U[j][i]);
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}

void forwardSubstitution(double L[N][N], double b[N], double y[N]) {
    for (int i = 0; i < N; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
    }
}

void backwardSubstitution(double U[N][N], double y[N], double x[N]) {
    for (int i = N - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < N; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] = x[i] / U[i][i];
    }
}

void printMatrix(double matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printVector(double vector[N]) {
    for (int i = 0; i < N; i++) {
        printf("%f\n", vector[i]);
    }
}


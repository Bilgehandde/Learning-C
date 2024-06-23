#ifndef MY_ARRAY_LIBRARY_H
#define MY_ARRAY_LIBRARY_H
#define N 5
#include <stdbool.h>

// Fonksiyon prototipleri
/* LU ayrýþýmý ve Gauss çözümü için olanlar*/
void LUdecomposition(double A[N][N], double L[N][N], double U[N][N]);
void forwardSubstitution(double L[N][N], double b[N], double y[N]);
void backwardSubstitution(double U[N][N], double y[N], double x[N]);
void printMatrix(double matrix[N][N]);
void printVector(double vector[N]);

void search_value(int **array, int rows, int cols, int value, int **result, int *result_count);
int* find_non_repeated_elements(int **array, int rows, int cols, int *non_repeated_count);
int find_min_element(int **array, int rows, int cols);
void find_max_elements_each_row(int **array, int rows, int cols, int *max_elements);
void sort_rows_descending(int **array, int rows, int cols);
void transpose_matrix(int **array, int rows, int cols, int **result);
void multiply_matrices(int **array1, int **array2, int size, int **result);
bool is_identity_matrix(int **array, int size);
bool is_symmetric_matrix(int **array, int size);


#endif

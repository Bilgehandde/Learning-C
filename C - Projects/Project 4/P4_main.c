#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_array_library.h"

int main() {
	// Kullanýcýdan satýr ve sütun sayýlarýný al
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Ýki matris oluþtur ve rastgele deðerlerle doldur
    int **array1 = (int **)malloc(rows * sizeof(int *));
    int **array2 = (int **)malloc(rows * sizeof(int *));
    int **array_ = (int **)malloc(rows * sizeof(int *));
    int **res = (int **)malloc(rows * sizeof(int *));
    srand(time(NULL)); // Rastgele sayýlar
    for (int i = 0; i < rows; i++) {
        array1[i] = (int *)malloc(cols * sizeof(int));
        array2[i] = (int *)malloc(cols * sizeof(int));
        array_[i] = (int *)malloc(cols * sizeof(int));
        res[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            array1[i][j] = (rand() % 19) -9; // -10 ile 10 arasýnda rastgele deðerler
            array2[i][j] = (rand() % 19) -9; // -10 ile 10 arasýnda rastgele deðerler
        }
    }
    
    printf("Matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", array1[i][j]); 
        }
        printf("\n");
    }
    printf("\n");
    
    printf("Matrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", array2[i][j]); 
        }
        printf("\n");
    }
    printf("\n");
    
    

	int value,value2;
    printf("Enter the value to search for Array-1 : ");
    scanf("%d", &value);
	printf("Enter the value to search for Array-2 : ");
    scanf("%d", &value2);
    int *result;
    int result_count;
    search_value(array1, rows, cols, value, &result, &result_count);
    // Sonuçlarý yazdýralým
    printf("\nFound %d occurrences of value %d at the following indices:\n", result_count, value);
    for (int i = 0; i < result_count*2 ; i += 2) {
        printf("(%d, %d)\n", result[i]+1, result[i + 1]+1);
    }
    result_count = 0;
    search_value(array2, rows, cols, value2, &result, &result_count);
    printf("Found %d occurrences of value %d at the following indices:\n", result_count, value2);
    for (int i = 0; i < result_count*2 ; i += 2) {
        printf("(%d, %d)\n", result[i]+1, result[i + 1]+1);
    }

    printf("\n------------------------------------\n");
    int option;
    printf("Select the array to perform the operations (1 or 2) ==> ");
    scanf("%d",&option);
    array_ = (option == 1) ? array1 : array2;
    
    printf("\n------------------------------------\n");
	int non_repeated_count;
    int *non_repeated_elements = find_non_repeated_elements(array_, rows, cols, &non_repeated_count);
    printf("Non-repeated elements: ");
    for (int i = 0; i < non_repeated_count; i++) {
        printf("%d ", non_repeated_elements[i]);
    }
    printf("\n");
    free(non_repeated_elements);
    
    printf("\n------------------------------------\n");
    int min_element = find_min_element(array_, rows, cols);
    printf("Min element: %d\n", min_element);
	
	printf("\n------------------------------------\n");
    int *max_elements = (int *)malloc(rows * sizeof(int));
    find_max_elements_each_row(array_, rows, cols, max_elements);
    printf("Max elements of each row: ");
    for (int i = 0; i < rows; i++) {
        printf("%d ", max_elements[i]);
    }
    printf("\n");
    free(max_elements);
	
	printf("\n------------------------------------\n");
    int **transpose = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++) {
        transpose[i] = (int *)malloc(rows * sizeof(int));
    }
    transpose_matrix(array_, rows, cols, transpose);
    printf("Transposed matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%3d ", transpose[i][j]);
        }
        printf("\n");
    }
    transpose_matrix(array_, rows, cols, transpose);
    for (int i = 0; i < cols; i++) {
        free(transpose[i]);
    }
    free(transpose);
    
    printf("\n------------------------------------\n");
    sort_rows_descending(array_, rows, cols);
    printf("Sorted matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", array_[i][j]);
        }
        printf("\n");
    }
    
    printf("\n------------------------------------\n");
    multiply_matrices(array1, array2, rows, res);
    // Sonuç matrisinin yazdýrýlmasý
    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%3d ", res[i][j]);
        }
        printf("\n");
    }
    free(res);
	printf("\n------------------------------------\n");
    
    // Kimlik matrisi kontrolü
    bool is_identity = is_identity_matrix(array_, rows);
    printf("Is the matrix an identity matrix? %s\n", is_identity ? "==> Yes" : "==> No");

	printf("\n------------------------------------\n");
	
    // Simetrik matris kontrolü
    bool is_symmetric = is_symmetric_matrix(array_, rows);
    printf("Is the matrix a symmetric matrix? %s\n", is_symmetric ? "==> Yes" : "==> No");
	printf("\n------------------------------------\n");
	
	getchar();
    
    printf("Press Enter to continue...\n");
    while (getchar() != '\n');
    printf("Continuing...\n");
    printf("------------------------------------\n");
    
	double A[N][N] = {
        {9, 0, -3, 0, 0},
        {4, -4, 0, 0, 0},
        {0, -2, 9, 0, 0},
        {0, 1, 6, -9, 2},
        {5, 1, 0, 0, -6}
    };

    double b[N] = {120, 0, 350, 0, 0};

    double L[N][N] = {0};
    double U[N][N] = {0};
    double y[N] = {0};
    double x[N] = {0};

    LUdecomposition(A, L, U);
	printf("\n------------------------------------\n");
    printf("Lower Triangular Matrix L:\n");
    printMatrix(L);
	printf("\n------------------------------------\n");
    printf("Upper Triangular Matrix U:\n");
    printMatrix(U);
	printf("\n------------------------------------\n");
    forwardSubstitution(L, b, y);
    printf("Solution of Ly = b (y vector):\n");
    printVector(y);
	printf("\n------------------------------------\n");
    backwardSubstitution(U, y, x);
    printf("Solution of Ux = y (x vector):\n");
    printVector(x);
	printf("\n------------------------------------\n");
	
	
	for (int i = 0; i < rows; i++) {
        free(array1[i]);
        free(array2[i]);
        free(res[i]);
    	free(array_[i]);
    }
    free(array1);
    free(array2);
    free(res);
    free(array_);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define x 3
#define y 3

//OLCHLT
// Matrisi ekrana yazdýrýr
void printMatrix(int matrix[x][y]) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Matrisin toplamýný hesaplar
int sumMatrix(int matrix[x][y]) {
    int sum = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Bir matrisin belirli bir sütununun toplamýný hesaplar
int sumColumn(int matrix[x][y], int column) {
    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += matrix[i][column];
    }
    return sum;
}

// Bir matrisin belirli bir satýrýnýn toplamýný hesaplar
int sumRow(int matrix[x][y], int row) {
    int sum = 0;
    for (int j = 0; j < y; j++) {
        sum += matrix[row][j];
    }
    return sum;
}

// Belirli bir konumdaki öðeyi güncelleyer
void updateElement(int matrix[x][y], int row, int column, int newValue) {
    matrix[row][column] = newValue;
}

int main() {
    int matrix[x][y] = {{10, 24, 3}, {6, 8, 22}, {36, 78, 90}};
	int a,b,c;
    printf("Matris ==>\n");
    printMatrix(matrix);

    printf("\nToplam ==> %d\n", sumMatrix(matrix));
	
	printf("Choose row for summation ==>");
	scanf("%d",&a);
	
    int xum = sumRow(matrix, a);
    printf("\n1. satýrýn toplamý ==> %d\n", xum);
	
	printf("Choose column for summation ==>");
	scanf("%d",&b);
	
    int yum = sumColumn(matrix, b);
    printf("\n2. sütunun toplamý ==> %d\n", yum);
	
	printf("Choose row and column for change ==> ");
	scanf("%d%d",&a,b);
	
	printf("Choose number for change ==> ");
	scanf("%d",c);
	
    printf("\nMatrisin güncellenmiþ hali ==>\n");
    updateElement(matrix, a, b, c);
    printMatrix(matrix);

    return 0;
}

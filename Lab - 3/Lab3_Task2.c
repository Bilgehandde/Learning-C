#include <stdio.h>
#include <stdlib.h>

/* OLCHLT */


int i,j;

void createArray(int arr[4][4])
{
    // Boþ dizi oluþtur
    for (i = 0; i < 4; i++) 
        for (j = 0; j < 4; j++) 
            arr[i][j] = 0;
        
    
}

void EnterElements(int arr[4][4])
{
    printf("Enter Elements ==> \n");
    for (i = 0;i<4;i++) 
       for (j = 0;j<4;j++)
          scanf("%d", &arr[i][j]);
    
}

void print(int arr[4][4]) 
{
    printf("Array elements:\n");
    for (i = 0; i < 4; i++) 
	{
        for (j = 0; j < 4; j++) 
            printf("| %d |", arr[i][j]);
        printf("\n");
    }
}

int countNegative(int arr[4][4]) 
{	
    int flag = 0;
	for (i = 0; i < 4; i++) 
        for (j = 0; j < 4; j++) 
            if (arr[i][j] < 0) 
                flag++;        
	return flag;
}
int main() {
	int arr[4][4];

    createArray(arr);
    EnterElements(arr);
    print(arr);

    int k = countNegative(arr);
    printf("Have %d negavite number." ,k);

    return 0;
}

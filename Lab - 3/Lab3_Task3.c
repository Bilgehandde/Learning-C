#include <stdio.h>
#include <stdlib.h>

void createArray(int arr[5][5], int a, int b) {
    int i,j;
    for (i = 0; i < a; i++) 
        for (j = 0; j < b; j++) 
            arr[i][j] = 0;  
}
void EnterElements(int arr[5][5], int a, int b) 
{
    int i,j;
    printf(" < %d elements needs for the array > \n",a*b);
    for (i = 0; i < a; i++) 
    {
        for (j = 0; j < b; j++)
        {
            printf("Elements for (%d,%d) ==> ", i+1, j+1);
            scanf("%d", &arr[i][j]); 
		}
	}
}

void print(int arr[5][5], int a, int b) 
{
    int i, j;
    printf("Array elements:\n");
    for (i = 0; i < a; i++) 
	{
        for (j = 0; j < b; j++) 
            printf("| %d |", arr[i][j]);
    
    	printf("\n");
	}
}

int MaxElement(int arr[5][5], int a, int b) 
{	 
	int i,j;
    int max_ = arr[0][0];
    for (i = 0; i < a * b; i++) {
        if (arr[i / b][i % b] > max_)
            max_ = arr[i / b][i % b];
    }
    return max_;
}

int main() {
    int a, b;
    printf("Choose rows ==> ");
    scanf("%d", &a);
    printf("Choose columns ==> ");
    scanf("%d", &b);

    int arr[5][5];

    createArray(arr, a, b);
    EnterElements(arr, a, b);
    print(arr, a, b);

    int max = MaxElement(arr , a , b);
    printf("Maximum value: %d\n", max);

    return 0;
}

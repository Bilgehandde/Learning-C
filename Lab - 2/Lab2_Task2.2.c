#include <stdio.h>
#include <stdlib.h>

/* OLCHLT */

int main() 
{	
	int number,i = 1;
	long long int factorial;
	
	
	printf("Enter a number ==> ");
	scanf("%d",&number);
	factorial = 1;
	for (i; i<=number; i++)
	{
		factorial *= i;	
	}
	printf("Factorial of Number ==> %d",factorial);
	
	return 0;
}

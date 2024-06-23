#include <stdio.h>
#include <stdlib.h>

/* OLCHLT */

int main() 
{	
	int number,i = 1;
	long long int factorial = 1;
	
	
	printf("Enter a number ==> ");
	scanf("%d",&number);
	
	for(i=1;i <= number;i++)
	{
		factorial *= i;
			
	}
	
	printf("Factorial of Number ==> %lld",factorial);
	
	return 0;
}

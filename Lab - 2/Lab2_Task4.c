#include <stdio.h>
#include <stdlib.h>

/* OLCHLT */

int main() {
	
	int number,result,i,sum = 0;
	
    printf("Enter a number ==> ");
    scanf("%d",&number);
     
    for(i=2; i<=number; i++) 
	{	
	 	result = number % i;
	 	
	 	if(result == 0)
	 	{
		 	printf("%d\n",i);
			sum += i;
		}
	}
	printf("Sum of divisors ==> %d",sum+1);

	return 0;
}

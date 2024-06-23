#include <stdio.h>
#include <stdlib.h>

/* OLCHLT */

int main() {
	
	int number,mult,i;
	
	printf("Enter a number (0 to 9) ==> ");
	scanf("%d",&number);
	
	for(i=0;i<=9;i++)
	{
	    mult = i*number;	
		printf("%d X %d ==> %d\n",i,number,mult);	
	}
	return 0;
}

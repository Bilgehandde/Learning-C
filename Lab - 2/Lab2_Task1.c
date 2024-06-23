#include <stdio.h>
#include <stdlib.h>

/* OLCHLT */

int main() 

{
	int num;
	long int result = 0;

	while (99)
	{
		
		printf("Enter a number (0 will end loop) ==>  ");
		scanf("%d",&num);
		
		if(num == 0)
			break;
		
		if(num > result)
			result = num;
	}
	printf("The Biggest number ==> %ld",result);
	
	return 0;
}

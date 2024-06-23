#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1
#define bool int


int main() {

	int x, y;
    bool result;
	
	printf("Enter x value ==> ");
	scanf("%d",&x);
	
	printf("Enter y value ==> ");
	scanf("%d",&y);
	
	result = (x > y);
	
	printf("\n\n(x > y ) ? ==>  %d\n", result);
	
	result = (x == y); 
    printf("(x == y ) ? ==>  %d\n", result);
    
    result = (x != y);
    printf("(x != y ) ? ==>  %d\n", result);
    
    result = (x > 0) && (y > 0);  
    printf("(x > 0) and (y > 0) ? ==>  %d\n", result);

	return 0;
}

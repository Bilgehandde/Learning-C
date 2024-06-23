#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	// Fonskiyonlar Radyan birimi ile çalýþýr !!!!!
	
	double x, y, _result;
	
	printf("Enter x value ==> ");
	scanf("%lf",&x);
	
	printf("Enter y value ==> ");
	scanf("%lf",&y);

	printf("\n Our Function Explanation \n");
	printf("****** Function 1 ==> f(x)   = sin(x) * pi \n"); 
    printf("****** Function 2 ==> f(x)   = cos(x) * pi \n"); 
    printf("****** Function 3 ==> f(x,y) = sin(y) * cos(x) * pi \n"); 
    printf("****** Function 4 ==> f(x,y) = x*sin(y) * cos(x) * pi \n"); 
    printf("****** Function 5 ==> f(x,y) = exp(y) * x * sin(x) * cos(y) * pi \n"); 
	
	_result = sin(x) * M_PI;
    printf("Function 1 ==> %lf\n", _result);
    
    _result = cos(x) * M_PI;
    printf("Function 2 ==> %lf\n", _result);
    
    _result = sin(y) * cos(x) * M_PI;
    printf("Function 3 ==> %lf\n", _result);
    
    _result = x * sin(y) * cos(x) * M_PI;
    printf("Function 4 ==> %lf\n", _result);
    
    _result = exp(y) * x * sin(x) * cos(y) * M_PI;
    printf("Function 5 ==> %lf\n", _result); 
	
	return 0;
}

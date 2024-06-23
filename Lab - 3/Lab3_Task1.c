#include <stdio.h>
#include <stdlib.h>

/* OLCHLT */

int main() {
	 
    int a1[] = {-4,6, 21, 13};
	int a2[] = {9, -7, 33, 0};
	int j, size_;
	
	// sizeof(a1): a1 dizisinin toplam bellek boyutunu verir.
	// sizeof(a1[0]): a1 dizisinin ilk elemanýnýn bellek boyutunu verir
    // int size_ = sizeof(a1) / sizeof(a1[0]) ile dizinin boyutu hatasýz bulunabilir 
	for (j=0;j<4;j++) 
	{
        printf("==> %d \n", a1[j]+a2[j]);
    }
    return 0;	
}	
	

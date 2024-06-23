#include <stdio.h>
int main() {
   FILE *file;
   char name[20];
   char surname[20];
   char job[20];
   char a[15];
   int age;
   
   printf("Isim giriniz:");
   scanf("%c",&a);
   

   file = fopen("Person.txt", "r");

   if (file == NULL) {
       printf("Error opening the file.\n");
       return 1;
   }


   while (fscanf(file, "%s%s%s%d", name, surname, job, &age) == 4) {
       if (strcmp(name, "Emrah") == 0) {
           printf("%s, %s, %d\n", surname, job, age);
       }
   }


   // Close the file
   fclose(file);
   return 0;
}



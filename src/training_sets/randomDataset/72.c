//#include <stdio.h>

int main() {
   char s1[] = "TajMahal";    // String Given
   char s2[8];                // Variable to store reverse string

   int length = 0;
   int loop = 0;

   while(s1[length] != '\0') {
      length++;
   }

   printf("\nPrinting in reverse - ");
   for(loop = --length; loop>=0; loop--)
      printf("%c", s1[loop]);

   loop = 0;
   printf("\nStoring in reverse  - ");

   while(length >= 0) {
      s2[length] = s1[loop];
      length--;
      loop++;
   }

   s1[loop] = '\0';           // Terminates the string

   printf("%s\n", s2);

   return 0;
}

//#include<stdio.h>
 
int main() {
   char ch = '*';
   int i, j, no_of_spaces = 4, spaceCount;
 
   for (i = 1; i <= 5; i++) {
      for (spaceCount = no_of_spaces; spaceCount >= 1; spaceCount--) {
         printf("  "); //2spaces
      }
 
      for (j = 1; j <= i; j++) {
         printf("%2c", ch);
      }
 
      printf("\n");
      no_of_spaces--;
   }
   return 0;
}

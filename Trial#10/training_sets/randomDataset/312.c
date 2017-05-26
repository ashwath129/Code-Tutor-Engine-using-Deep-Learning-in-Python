//#include<stdio.h>
 
int main() {
   int i, j;
   char ch = '*';
 
   for (i = 4; i >= 0; i--) {
      printf("\n");
      for (j = 0; j < i; j++)
         printf("%c", ch);
   }
   return(0);
}

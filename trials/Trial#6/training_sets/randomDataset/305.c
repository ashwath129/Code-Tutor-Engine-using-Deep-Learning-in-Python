//#include<stdio.h>
 
int main() {
   int i, j, num = 2;
 
   for (i = 0; i < 4; i++) {
      num = 2;
      for (j = 0; j <= i; j++) {
         printf("%d\t", num);
         num = num + 2;
      }
      printf("\n");
   }
 
   return (0);
}

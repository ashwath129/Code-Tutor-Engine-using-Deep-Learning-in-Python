//#include<stdio.h>
 
int main() {
   int i, j;
   for (i = 0; i < 10; i++) {
      printf("\n");
      for (j = 0; j < 10; j++) {
         if (i == 0 || i == 9 || j == 0 || j == 9)
            printf("1");
         else
            printf("-");
      }
   }
   return (0);
}

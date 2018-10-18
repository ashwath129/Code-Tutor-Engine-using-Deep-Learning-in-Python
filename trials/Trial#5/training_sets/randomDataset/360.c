//#include <stdio.h>

int main() {
   int i, j, count;

   for(i = 1; i <= 10; i++) {
      for(j = i; j <=100; j += 10 )
         printf(" %3d", j);

      printf("\n");
   }

   return 0;
}

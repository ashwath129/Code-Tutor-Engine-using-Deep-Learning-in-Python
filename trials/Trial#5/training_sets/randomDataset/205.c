//#include <stdio.h>

int main() {
   int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
   int loop, smallest;

   smallest = array[0];
   
   for(loop = 1; loop < 10; loop++) {
      if( smallest > array[loop] ) 
         smallest = array[loop];
   }
   
   printf("Smallest element of array is %d", smallest);   
   
   return 0;
}

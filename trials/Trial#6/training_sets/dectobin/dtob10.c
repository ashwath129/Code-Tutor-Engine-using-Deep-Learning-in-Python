//#include <stdio.h>
int main() {
  long decimal, n, binary=0, i=1, remainder;
  printf("Please Enter a decimal number : ");
  scanf("%ld", &decimal);
  n=decimal;
  while(n != 0) {
    remainder = n%2;
    n = n/2;
    binary= binary + (remainder*i);
    i = i*10;
  }
  printf("Binary number of %ld is %ld\n", decimal, binary);
 
  return 0;
}

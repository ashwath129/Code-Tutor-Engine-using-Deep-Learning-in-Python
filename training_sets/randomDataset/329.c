//#include<stdio.h>
 
int main() {
   int number = 12354;
   int sum = 0;
 
   for (; number > 0; sum += number % 10, number /= 10);
 
   printf("\nSum of the Digits : %d", sum);
}

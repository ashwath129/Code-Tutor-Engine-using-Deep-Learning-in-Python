//#include<stdio.h>
int main() {
 int i, j;
 
 for (i = 0; i <= 6; i++) {
 for (j = 0; j <= i; j++) {
 printf("%d\t", i * j);
 }
 printf("\n");
 }
 return(0);
}

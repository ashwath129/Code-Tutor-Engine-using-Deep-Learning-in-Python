
//#include <stdio.h>

int main() 
{
 int num, bin_num[100], dec_num, i,j;

 // Read an integer number
 printf("Enter an integer number\n");
 scanf("%d",&num);
 dec_num = num;

 // Convert Decimal to Binary
 i=0;
 while (dec_num) {
	bin_num[i] = dec_num % 2;
	dec_num = dec_num / 2;
	i++;
 }
 
 // Print Binary Number
 printf("The binary value of %d is ",num);
 for (j=i-1; j>=0; j-- ) {
	 printf("%d",bin_num[j]);
 }

return 0;
}

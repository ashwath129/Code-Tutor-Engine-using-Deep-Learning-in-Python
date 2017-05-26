#include<stdio.h>
#include<stdlib.h>
 
void conversion(int num, int base)
{
	int remainder = num % base;	
	if(num == 0)
	{
		return;
	}
	conversion(num / base, base);
	if(remainder < 10)
	{
		printf("%d", remainder);	
	}
}
 
int main()
{
	int num, choice;
	printf("\nEnter a Positive Decimal Number:\t");
	scanf("%d", &num);
	printf("\nBinary Value:\t");
	conversion(num, 2);
	printf("\n");
	return 0;
}
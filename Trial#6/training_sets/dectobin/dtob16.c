//#include<stdio.h>
int main()
{
	int dec,rem,i=1;
	long int bin=0;
	printf("Enter the decimal number : ");
	scanf("%d",&dec);
	while(dec>0)
	{
		rem=dec%2;
		dec=dec/2;
		bin=bin+(i*rem);
		i=i*10;
	}
	printf("The binary number is %ld",bin);
	return 0;
}

//#include<stdio.h>
void main()
{
	long int a,c,sum=0,n;
	printf("\nEnter the number....");
	scanf("%ld",&a);
	n=a;
	do
	{
		sum=0;
		while(n)
		{
			c=n%10;
			sum=sum+c;
			n=n/10;
		}
		n=sum;
	}while(sum>9);
	printf("%d",sum);
}

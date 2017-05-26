//#include<stdio.h>
main()
{
	long int a;
	int b,sum=0;
	printf("\nEnter the no:");
	scanf("%ld",&a);
	
	do
	{
		sum=0;
		while(a)
		{
			b=a%10;
			sum+=b;
			a=a/10;
		}
		a=sum;
	}while(sum>9);
	
	printf("\nsum=%d",sum);
}			

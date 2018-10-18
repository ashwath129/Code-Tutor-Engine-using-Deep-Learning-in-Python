//#include<stdio.h>
void main()
{
	long int r,sum=0,n;
	printf("\n enter n");
	scanf("%ld",&n);
	while(n!=0)
	{
		r=n%10;
		sum=sum+r;
		n=n/10;
		if((n<=0)&&(sum>9))
		{			
			n=sum;
			sum=0;
			continue;
		}
	}
	printf("\n%ld is the sum",sum);
}

//#include<stdio.h>
int main()
{
	long int n;
	int sum=0;
	scanf("%ld",&n);
	while(n!=NULL || sum>=10 )
	{
		if(n==NULL)
		{
			n=sum;
			sum=0;
		}
		int rem=n%10;
		n=n/10;
		sum=sum+rem;
	}
	printf("%d",sum);
	return 0;
}

//#include<stdio.h>
int main()
{
	int n; 
	scanf("%d",&n);
	int sum = 0;
	while (n > 0)
	{
		int p = n % 10;
		sum = sum + p;
		n = n / 10;
		if(n==0 && sum>9)
		{
			n=sum;
			sum=0;
		}
	}
	printf("%d",sum);
	return 0;
}

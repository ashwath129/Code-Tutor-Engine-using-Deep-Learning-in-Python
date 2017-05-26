//#include<stdio.h>
int main()
{
	int sum=0,r;
	long int n;
	printf("enter the number\n");
	scanf("%ld",&n);
	label:
	while(n<0)
	{
		r=n%10;
		sum=sum+r;
		n=n/10;
	} 
	if(sum>9) 
	{ 
		goto label; 
	} 
	else
	{
		printf("the value of sum=%d",sum);
	}
}

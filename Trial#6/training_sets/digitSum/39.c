//#include<stdio.h>
void main()
{
	long int n;
	int sum=0;
	printf("enter the number");
	scanf("%ld",&n);
	new:
	while(n>0)
	{
		n=n%10;
		sum+=n;
		n=n/10;
	}
	if(sum>9)
		goto new;
  	printf("sum is %d",sum);
}

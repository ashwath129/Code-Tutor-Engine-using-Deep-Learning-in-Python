//#include<stdio.h>
void main()
{
	long int ch;
	int sum=0,n,x,sum1=0;
	printf("enter the value");/*4 digit no*/
	scanf("%ld",&ch);
	while(ch>0)
	{
		n=ch%10;
		ch=ch/10;
		sum=sum+n;
	}
	printf("%d\n",sum);
	goto loop;

	loop:

	while(sum>10)
	{
		x=sum%10;
		sum=sum/10;
		sum1=sum1+x+sum;
	}
	if (sum1>10)
	{
		goto loop;
	}
	else
	{
		printf("%d\n",sum1);
	}
}

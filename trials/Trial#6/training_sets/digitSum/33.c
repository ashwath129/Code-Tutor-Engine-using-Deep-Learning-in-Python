//#include<stdio.h>
void main()
{
	long int x;
	int n,sum,v;
	printf("\nenter the number");
	scanf("%ld",&x);
	v:
	sum=0;
	while(x!=0)
	{
		n=x%10;
	 	sum+=n;
	  	x=x/10;
	}
    if(sum<9)
    {
		printf("the sum of the digits=%d",sum);
	}
    else
	{
		x=sum;
		goto v;         
	} 
}

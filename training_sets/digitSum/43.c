//#include<stdio.h>
void main()
{ 
	int r; 
	long int n,sum=0; 
	printf("enter the number\n"); 
	scanf("%ld",&n); 
	label: 
	while(n>0) 
	{ 
		r=n%10;
		sum=sum+r;
		n=n/10;
	}
	if(sum>9)
	{
		n=sum;
		sum=0;
		goto label;
	}
	else
	{
		printf("Sum is: %d\n", sum);
	}
}

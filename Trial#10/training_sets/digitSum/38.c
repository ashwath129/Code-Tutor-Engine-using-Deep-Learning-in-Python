//#include<stdio.h>
void main()
{
	long int a,k,b,n,r=0,s;
	printf("enter the number..");
	scanf("%ld",&n);
	while(n>0)
	{ 
		a=n%10;
		r=r+a;
		n=n/10;
	}
	k:
	if(r>10)
	{ 
		s=r; 
		r=0;
	}
	while(s>0)
	{
		b=s%10;
		r=r+b;
		s=s/10;
	}
	if(r>10)
		goto k;
	printf("the value is %d",r);
}

//#include<stdio.h>
void main()
{
	unsigned int n,c=0,r,i,S=0;
	printf("enter no.");
	scanf("%d",&n);
	while(n>0)
	{
		while(n>0)
		{
			r=n%10;
			c=c+r;
			n=n/10;
		}
		if(c>9)
		{
			int X=c%10;
			int Y=c/10;
			S=X+Y;
		}
	}
	if(c<10)
		printf("%d",c);
	else
		printf("%d",S);
}

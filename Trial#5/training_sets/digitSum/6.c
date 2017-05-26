//#include<stdio.h>
void main()
{
	int n,r,m;
	int s=0;
	printf("Enter Number");
	scanf("%d",&n);
	m=n;
	repeat:
	while (n>0)
	{
		r=n%10;
		s=s+r;
		n=n/10;
	}
	if(s>9)
	{
		n=s;
		s=0;
		goto repeat;
	}
	cout<<"Sum of digits of the number "<<m<<" is "<<s;
	getch();
}

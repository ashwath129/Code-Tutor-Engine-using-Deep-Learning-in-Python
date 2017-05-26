//#include<stdio.h>
void main()
{
	long int a;
	int cnt=0,i,j;
	long int sum=0;
	printf("\n enter values..");
	scanf("%ld",&a);
	w:
	while(a!=0)
	{
		i=a%10;
		a/=10;
		sum+=i;
	}
	if(sum>9)
	{ 
        a=sum;
		i=0;
		sum=0;
		goto w;
	}
	else
	{
		printf("%d",sum);
		return;
	}
}		

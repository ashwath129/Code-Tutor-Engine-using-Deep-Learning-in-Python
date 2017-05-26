//#include<stdio.h>
main()
{
	int a,b,c,d,e;
	float total;
	float percent;
	printf("hindi=");
	scanf("%d",&a);
	printf("english=");
	scanf("%d",&b);
	printf("math=");
	scanf("%d",&c);
	printf("physics=");
	scanf("%d",&d);
	printf("chemistry=");
	scanf("%d",&e);
	total=a+b+c+d+e;
	percent=total/5;
	printf("percentage=%f",percent);
}


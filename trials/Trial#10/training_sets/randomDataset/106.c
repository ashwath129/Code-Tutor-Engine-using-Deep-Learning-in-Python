//#include<stdio.h>
//suppose a=1
//suppose b=2
//a=a+b   1+2=3
//b=a-b   3-2=1
//a=a-b   3-1=2
main()
{
	int a,b;
	printf("A=");
	scanf("%d",&a);
	printf("B=");
	scanf("%d",&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("*********** after swaping ************\n");
	printf("A=%d",a);
	printf("\nB=%d",b);
}

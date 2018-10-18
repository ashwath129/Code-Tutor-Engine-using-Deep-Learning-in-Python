//#include<stdio.h>
void main()
{
	unsigned int no;
	printf("Enter number : ");
	scanf("%d", &no);
	if(no==0)
		printf("sum = 0");
	else
	{
		no=no%9;
		if(no==0)
			printf("sum = 9");
		else
			printf("sum = %d", no);
	}
}

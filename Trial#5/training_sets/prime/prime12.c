//#include<stdio.h>
void main()
{
   	int n, i, j, count;
   	printf("Enter any number\n");
   	scanf("%d", &i);
   	count = 0;
   	for(j = 1; j <=i; j++)
	{
	   	if(i % j == 0)
	   	{
	   		count++;
	   	}
	}
   	if(count == 2)
   	{
   		printf("prime");
    }
    else
    {
    	printf("Not prime");
    }
}

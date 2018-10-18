//#include<stdio.h>
main()
{
	int num;
	printf("Enter number:");
	scanf("%d", &num);
	int sum, a;
	sum = 0;	
	while(num>0){
		while(num!=0)
		{
 			a=num%10;
			sum+=num;
			num = num/10;
		}
		if(num>9)
		{
			num = sum;
			sum = 0;
		}
	}
	printf("Result : %d", sum);
}

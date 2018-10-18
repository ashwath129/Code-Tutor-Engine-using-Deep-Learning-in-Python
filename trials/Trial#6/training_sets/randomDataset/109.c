//#include<stdio.h>
main()
{
	int a;
	printf("ENTER THE CHOICE = ");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
		printf("monday");
		break;
		case 2:
		printf("tuesday");
		break;
		case 3:
		printf("wednesday");
		break;
		default:
		printf("you enter wrong choice");
		break;
	}
}

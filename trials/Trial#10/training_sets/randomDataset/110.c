//#include<stdio.h>
void main() {
	int a;
	printf("enter your choice=");
	scanf("%d", &a);
	switch (a) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("one");
		break;
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		printf("two");
		break;
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		printf("three");
		break;
	default:
		printf("wrong choice");
	}
}

//#include<stdio.h>
void main(void) {
	int a, b, t, r;
	printf("Enter the 1st No.:");
	scanf("%d", &a);
	printf("Enter the 2nd No.:");
	scanf("%d", &b);
	if (a != b)
		if (a > b) {
			t = a;
			a = b;
			b = t;
		}
	do {
		r = a % b;
		a = b;
		b = r;
	} while (r > 0);
	printf("The HCF:%d", a);
}		

//#include<stdio.h>
void main(void) {
	int a = 1, b = 2, c, i;
	printf("\t%d", a);
	for (i = 1; i <= 6; i++) {
		c = a + b;
		printf("\t%d", c);
		b = a;
		a = c;
	}
}

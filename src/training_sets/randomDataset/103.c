//#include<stdio.h>
void main() {
	float pam, p, d, tam, ri;
	printf("Enter the principal amount:");
	scanf("%f", &pam);
	printf("Enter the rate of interest:");
	scanf("%f", &p);
	printf("Enter the duration in year:");
	scanf("%f", &d);
	ri = pam * p / 100;
	tam = pam + ri;
	printf("Interest amount=%f", ri);
	printf("Total amount=%f", tam);
}

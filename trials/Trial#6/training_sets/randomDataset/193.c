//#include <stdio.h>
//#include <math.h>
int main()
{
    long long n, decimalNumber=0, x, i=0, remainder;
    printf("Enter a binary number: ");
    scanf("%lld", &x);
	n=x;
	while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    printf("%lld in binary = %d in decimal", x, decimalNumber);
    return 0;
}

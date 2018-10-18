//#include <stdio.h>
//#include <math.h>
int main()
{
    long long n,x;
    printf("Enter a decimal number: ");
    scanf("%lld", &n);
    long long int binaryNumber = 0;
    int remainder, i = 1, step = 1;
	x=n;
    while (x!=0)
    {
        remainder = x%2;
        x /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    printf("%lld in decimal = %lld in binary", n, binaryNumber);
    return 0;
}

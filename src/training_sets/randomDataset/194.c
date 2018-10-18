int main()
{
    int n,x;
	long long binaryNumber = 0;
    int remainder, i = 1, step = 1;
    printf("Enter a decimal number: ");
    scanf("%d", &x);
	n=x;
	while (n!=0)
    {
        remainder = n%2;
        printf("Step %d: %d/2, Remainder = %d, Quotient = %d\n", step++, n, remainder, n/2);
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    printf("%d in decimal = %lld in binary", x, binaryNumber);
    return 0;
}
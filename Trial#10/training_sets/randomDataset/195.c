//#include <stdio.h>
//#include <math.h>
int main()
{
    int decimalNumber, n;
int octalNumber = 0, i = 1;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
decimalNumber = n;
while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    printf("%d in decimal = %d in octal", n, octalNumber);

    return 0;
}

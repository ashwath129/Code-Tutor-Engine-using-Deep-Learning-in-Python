//#include <stdio.h>
//#include <math.h>

int main()
{
    int octalNumber,x;
int decimalNumber = 0, i = 0;
    long long binaryNumber = 0;
    printf("Enter an octal number: ");
    scanf("%d", &x);
octalNumber=x;
while(octalNumber != 0)
    {
        decimalNumber += (octalNumber%10) * pow(8,i);
        ++i;
        octalNumber/=10;
    }

    i = 1;

    while (decimalNumber != 0)
    {
        binaryNumber += (decimalNumber % 2) * i;
        decimalNumber /= 2;
        i *= 10;
    }

    printf("%d in octal = %lld in binary", x, binaryNumber);

    return 0;
}

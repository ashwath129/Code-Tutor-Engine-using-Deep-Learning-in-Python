//#include <stdio.h>
//#include <math.h>
int main()
{
    int octalNumber,x;
int decimalNumber = 0, i = 0;
    printf("Enter an octal number: ");
    scanf("%d", &x);
	octalNumber = x;
while(octalNumber != 0)
    {
        decimalNumber += (octalNumber%10) * pow(8,i);
        ++i;
        octalNumber/=10;
    }

    i = 1;
    printf("%d in octal = %lld in decimal", x, decimalNumber);

    return 0;
}

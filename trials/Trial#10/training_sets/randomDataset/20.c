//#include <stdio.h>

//#include <math.h>

int main ()

{

    int bin, x;

 int a, b, result = 0, i = 0;

    printf("Enter a binary number: ");

    scanf("%d", &x);
	bin = x;
    while (bin != 0)

    {

        a = bin % 10;

        bin = bin / 10;

        b = bin % 10;

        if ((a && !b) || (!a && b))

        {

            result = result + pow(10, i);

        }

        i++;

    }

    printf("The gray code of %d is %d\n", x, result);

    return 0;

}

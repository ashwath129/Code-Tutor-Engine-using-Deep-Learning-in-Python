
//#include <stdio.h>

 

void main()

{

    int x = 1, i, n;

 

    printf("enter the number :");

    scanf("%d", &n);

    /* for positive values */

    if (n > 0)

    {

        for (; x <= n >> 1;)

        {

            x = x << 1;

        }

        n = x;

    }

    /* for negative values */

    else

    {

        n = ~n;

        n = n + 1;

        for (; x <= n >> 1;)

        {

            x = x << 1;

        }

        x = x << 1;

        x = ~x;

        x = x + 1;

        n = x;

    }

    printf("%d", n);

}

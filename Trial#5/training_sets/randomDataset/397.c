
//#include <stdio.h>

 

void main()

{

    int x, y;

 

    printf("Enter the values for X and Y\n");

    scanf("%d %d", &x, &y);

    if (x > 0 && y > 0)

        printf("point (%d, %d) lies in the First quandrant\n");

    else if (x < 0 && y > 0)

        printf("point (%d, %d) lies in the Second quandrant\n");

    else if (x < 0 && y < 0)

        printf("point (%d, %d) lies in the Third quandrant\n");

    else if (x > 0 && y < 0)

        printf("point (%d, %d) lies in the Fourth quandrant\n");

    else if (x == 0 && y == 0)

        printf("point (%d, %d) lies at the origin\n");

}

/*
 * C program to check whether a given integer is odd or even
 */
//#include <stdio.h>
 
void main()
{
    int ival, remainder;
 
    printf("Enter an integer : ");
    scanf("%d", &ival);
    remainder = ival % 2;
    if (remainder == 0)
        printf("%d is an even integer\n", ival);
    else
        printf("%d is an odd integer\n", ival);
}

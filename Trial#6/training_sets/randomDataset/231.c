
//#include <stdio.h>

 

void main()

{

    char s1[50], s2[10];

    int i, flag = 0;

    char *ptr1, *ptr2;

 

    printf("\nenter the string1:");

    scanf(" %[^\n]s", s1);    

    printf("\nenter the string2:");

    scanf(" %[^\n]s", s2);

 

    /*COMPARING THE STRING1 CHARACTER BY CHARACTER WITH ALL CHARACTERS OF STRING1*/

    for (i = 0, ptr1 = s1;*ptr1 !=  '\0';ptr1++)

    {

        i++;

        for (ptr2 = s2; *ptr2 != '\0';ptr2++)

        {

            if (*ptr1  ==  *ptr2)

            {

                flag = 1;

                break;

            }

        }

        if (flag  ==  1)

            break;

    }

 

    if (flag  ==  1)

        printf("\nfirst occurance of character of string2 in string1 is at position:%d and character is %c", i, *ptr2);

    else

        printf("\nnone of the characters of string1 match with mone of characters of string2");

}

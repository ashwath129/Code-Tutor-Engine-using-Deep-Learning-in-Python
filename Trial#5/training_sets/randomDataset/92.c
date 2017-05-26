
//#include <stdio.h>

//#include <string.h>

 

void main()

{

    char s1[100], ar[10][20], ar1[10][20], new[10];

    int i, j = 0, k = 0, l, count = 0, flag = 0, n, temp, len[20];

 

    printf("\nenter the string:");

    scanf(" %[^\n]s", s1);

 

    /*COPYING GIVEN STRING TO 2D ARRAY*/

    for (i = 0;s1[i] != '\0';i++,j++)

    {

        if (s1[i] >= 33 && s1[i] <= 64)

            i++;

        if (s1[i] == ' ')

        {

            ar[k][j] = '\0';

            k++;

            i++;

            j = 0;

        }

        ar[k][j] = s1[i];

    }

    ar[k][j] = '\0';

    /*PLACING THE REPEATED WORDS AND LENGTHS INTO NEW ARRAY*/

    l = 0;

    for (i = 0;i <= k;i++)

    {

        for (j = i + 1;j <= k;j++)

        {

            if (strcmp(ar[i], ar[j]) == 0)

            {

                for (n = 0;n < l && l != 0; n++)

                {

                    if (strcmp(ar[i], ar1[k]) == 0)

                    {

                        flag = 1;

                        break;

                    }

                }

                if (flag != 1)

                {

                    strcpy(ar1[l], ar[i]);

                    len[l] = strlen(ar1[l]);

                    l++;

                }

                flag = 0;

                break;

            }

        }

    }

    printf("\n");

    /*SORTING IS DONE BASED ON THEIR LENGTHS*/

    for (i = 0;i < l;i++)

    {

        for (j = i + 1;j < l;j++)

        {

            if (len[i] < len[j])

            {

                temp = len[i];

                strcpy(new, ar1[i]);

                len[i] = len[j];

                strcpy(ar1[i], ar1[j]);

                len[j] = temp;

                strcpy(ar1[j], new);

            }

        }

    }

    maxlen = len[0];

    for (i = 0;i < l;i++)

    {

        if (len[i] == maxlen)

            printf("\nthe longer repeating sequence of the given string is: %s", ar1[i]);

    }

}

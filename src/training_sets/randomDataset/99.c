
//#include <stdio.h>

//#include <string.h>

 

void main()

{

    int i, j = 0, k, k1 = 0, k2 = 0, row = 0;

    char temp[50];

    char str[100], str2[100], str1[5][20], str3[6][20], str4[60][40];

 

    printf("enter the string :");

    scanf(" %[^\n]s", &str);

    printf("enter string:");

    scanf(" %[^\n]s", &str2);

 

/* read strings into 2d character arrays */

    for (i = 0;str[i] != '\0'; i++)

    {

        if (str[i] == ' ')

        {

            str1[k1][j] = '\0';

            k1++;

            j = 0;

        }

        else

        {

            str1[k1][j] = str[i];

            j++;

        }

    }

    str1[k1][j] = '\0';

    j = 0;

    for (i = 0;str2[i] != '\0';i++)

    {

        if (str2[i] == ' ')

        {

            str3[k2][j] = '\0';

            k2++;

            j = 0;

        }

        else

        {

            str3[k2][j] = str2[i];

            j++;

        }

    }

    str3[k2][j] = '\0';

 

/* concatenates string1 words with string2 and stores in 2d array */    

    row = 0;

    for (i = 0;i <= k1;i++)

    {

        for (j = 0;j <= k2;j++)

        {

            strcpy(temp, str1[i]);

            strcat(temp, str3[j]);

            strcpy(str4[row], temp);

            row++;

        }

    }

    for (i = 0;i <= k2;i++)

    {

        for (j = 0;j <= k1;j++)

        {

            strcpy(temp, str3[i]);

            strcat(temp, str1[j]);

            strcpy(str4[row], temp);

            row++;

        }

    }

 

/* eliminates repeated combinations */

    for (i = 0;i < row;i++)

    {

        for (j = i + 1;j < row;j++)

        {

            if (strcmp(str4[i], str4[j]) == 0)

            {

                for (k = j;k <= row;k++)

                {

                    strcpy(str4[k], str4[k + 1]);

                }

                row--;

            }

        }

    }

 

/* displays the output */

    for (i = 0;i < row;i++)

    {

        printf("\n%s", str4[i]);

    }

}

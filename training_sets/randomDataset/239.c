
//#include <stdio.h>

//#include <string.h>
void main()
{
    char str1[50],  str2[50], str3[100][100], str4[100][100];
    char str5[200][200], temp[200], str[200][200];
    int i, j = 0, k = 0, l = 0, m = 0, index = 0, n = 0;
    printf("Enter first string\n");
    scanf("%[^\n]s", str1);
    printf("Enter second string\n");
    scanf(" %[^\n]s", str2);    
    for (i = 0;str1[i] != '\0';i++)
    { 
        if (str1[i] == ' ')
        {
            str3[j][k] = '\0';
            j++;
            k = 0;
        }
        else
        {
            str3[j][k] = str1[i];
            k++;
        }
        str3[j][k] = '\0';    
    }
    k = 0;
    for (i = 0;str2[i] != '\0';i++)
    {
        if (str2[i] == ' ')
        {
            str4[l][k] = '\0';
            l++;
            k = 0;
        }
        else
        {
            str4[l][k] = str2[i];
            k++;
        }
        str4[l][k] = '\0';
    }
    for (i = 0;i <= j;i++)
    {
        for (m = 0;m <= l;m++)
        {
            strcpy(temp, str3[i]);
            strcat(temp, str4[m]);
            strcpy(str5[index], temp);
            index++;
        }
    }    
    for (i = 0;i <= l;i++)
    {
        for (m = 0;m <= j;m++)
        {
            strcpy(temp, str4[m]);
            strcat(temp, str3[i]);
            strcpy(str5[index], temp);
            index++;
        }
    }

    for (i = 0;i <= index;i++)
    {
        for (j = i + 1;j <= index;j++)
        {
            if (strcmp(str5[i], str5[j]) == 0)
            {
               for (k = j;k <= index;k++)
                {
                    strcpy(str5[k], str5[k + 1]);
                }
                index--;
            }
        }
    }
    for (i = 0;i <= index;i++)
    {
        printf("%s\n", str5[i]);
    }
}

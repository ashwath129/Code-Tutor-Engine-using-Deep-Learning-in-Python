//#include <stdio.h>
//#include <string.h>
char s1[10], s2[10], s3[10];
int i, k;
char carry = '0';
void main()
{
	char *p1, *p2;
    printf("enter string1\n");
    scanf(" %[^\n]s", s1);
    printf("enter string2\n");
    scanf(" %[^\n]s", s2);
   p1 = s1;
    p2 = s2;
    k = strlen(s1);
    for (;*p1 != '\0' && *p2 != '\0';p1++, p2++);
    p1--;
    p2--;
    s3[k+1] = '\0';
    for (i = k + 1;i >= 1;i--, p1--, p2--)
    {
        if (*p1 == '0' && *p2 == '0'&& carry == '0')
        {
            s3[i] = (*p1 ^ *p2) ^ carry;
            carry = '0';
        }
        else if (*p1 == '0' && *p2 == '0' && carry == '1')
        {
            s3[i] = (*p1 ^ *p2)^ carry;
            carry = '0';
        }
        else if (*p1 == '0' && *p2 == '1' && carry == '0')
        {
            s3[i] = (*p1 ^ *p2)^ carry;
            carry = '0';
        }
        else if (*p1 == '0' && *p2 == '1' && carry == '1')
        {
            s3[i] = (*p1 ^ *p2)^ carry;
            carry = '1';
        }
        else if (*p1 == '1' && *p2 == '0' && carry == '0')
        {
            s3[i] = (*p1 ^ *p2)^ carry;
            carry = '0';
        }
        else if (*p1 == '1' && *p2 == '0' && carry == '1')
        {
            s3[i] = (*p1 ^ *p2)^ carry;
            carry = '1';
        }
        else if (*p1 == '1' && *p2 == '1' && carry == '0')
        {
            s3[i] = (*p1 ^ *p2)^ carry;
            carry = '1';
        }
        else
        {
            s3[i] = (*p1 ^ *p2)^ carry;
            carry = '1';
        }

    printf("binary addition of number is\n");
    if (carry == '1')
    {
        s3[i] = '1';
        for (i = 1;i <= k + 1;i++)
            printf("%c", s3[i]);
        printf("\n");
    }
    else
    {
        for (i = 1;i <= k + 1;i++)
            printf("%c", s3[i]);
        printf("\n");
    }
}

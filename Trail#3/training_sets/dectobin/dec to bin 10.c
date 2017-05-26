#include<stdio.h>
 
int decimal_to_binary(int dec_num)
{
    int rem, a = 1;
    long int bin_num = 0;
    while(dec_num > 0)
    {
        rem = dec_num%2;
        dec_num = dec_num/2;
        bin_num = bin_num + (a * rem);
        a = a * 10;
    }
    return bin_num;lang:default decode:true
}
 
int main()
{
    int dec_num, temp;
    printf("\nEnter A Decimal Integer:\t");
    scanf("%d", &dec_num);
    temp = dec_num;
    printf("\nBinary Equivalent of Decimal Integer %d: %d", temp, decimal_to_binary(dec_num));
    printf("\n");
    return 0;
}


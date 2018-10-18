//#include<stdio.h>
 
int main()
{
    int dec_num, rem, a = 1, temp;
    long int bin_num = 0;
    printf("\nEnter A Decimal Integer:\t");
    scanf("%d", &dec_num);
    temp = dec_num;
    while(dec_num > 0)
    {
        rem = dec_num%2;
        dec_num = dec_num/2;
        bin_num = bin_num + (a * rem);
        a = a * 10;
    }
    printf("\nBinary Equivalent of Decimal Integer %d: %ld", temp, bin_num);
    printf("\n");
    return 0;
}

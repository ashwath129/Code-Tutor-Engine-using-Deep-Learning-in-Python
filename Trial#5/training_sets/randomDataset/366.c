//#include <stdio.h>
#define NUM_BITS_INT (8*sizeof(int))
int main()
{
	unsigned int x;
    int i, count = 0, result, shift_num;
	printf("\nEnter Number");
	scanf("%d", &x);
	for (i = 0;i <= NUM_BITS_INT;i++)
    {
        shift_num = x >> i;
        result = shift_num & 1;
        if (res == 1)
            count++;
    }
    if (count % 2 == 1)
        printf("YES");
    else 
        printf("NO");
}

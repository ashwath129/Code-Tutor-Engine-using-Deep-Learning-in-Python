//#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int sum=(n % 9 == 0) ? 9 : (n % 9);
    printf("Sum=%d",sum);
    return 0;
}

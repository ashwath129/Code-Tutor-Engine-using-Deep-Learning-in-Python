//#include<stdio.h>
void main()
{
    long int n,n1,m=1,rem,ans=0;
    printf("\nEnter Your Decimal No (between 0 to 1023) :: ");
    scanf("%ld",&n);
    n1=n;
    while(n>0)
    {
        rem=n%2;
        ans=(rem*m)+ans;
        n=n/2;
        m=m*10;
    }

    printf("\nYour Decimal No is   :: %ld",n1);
    printf("\nConvert into Binary No is :: %ld",ans);
    printf("\n\n\n\tThank You");
}

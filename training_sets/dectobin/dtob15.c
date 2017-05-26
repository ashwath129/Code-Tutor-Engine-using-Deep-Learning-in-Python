//#include<stdio.h>
void main()
{
        int n,d=0,j,a[9];
        printf("Enter the Integer which u want to Convert Decimal to Binary : ");
        scanf("%d",&n);
        while(n>0)
               {
                    a[d]=n%2;
                    n=n/2;
                    d++;
               }  
                    printf("After Converting Decimal to Binary is : ");
                    for(j=d-1;j>=0;j--)
                         printf("%d",a[j]);
                         
}

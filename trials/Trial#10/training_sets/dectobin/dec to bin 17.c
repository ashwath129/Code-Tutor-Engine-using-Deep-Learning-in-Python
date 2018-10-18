#include
#include
void main()
{
int n,j,a[50],i=0;
clrscr();
printf("\n enter the value :-");
scanf("%d",&n);
while(n!=0)
{
a[i]=n%2;
i++;
n=n/2;
}
printf("\n binary conversion\n");
for(j=i-1;j>=0;j--)
printf("%d",a[j]);
getch();
}
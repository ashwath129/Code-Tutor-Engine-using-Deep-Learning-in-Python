#include<stdio.h>
#include<conio.h>
void main()
{
int d,rem,i=1;
long int bin=0;
printf("Enter the decimal number : ");
scanf("%d",&d);
while(d>0)
{
rem=d%2;
d=d/2;
bin=bin+(i*rem);
i=i*10;
}
printf("The binary number is %ld",bin);
getch();
}
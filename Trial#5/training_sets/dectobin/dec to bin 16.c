#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void binary(int);
main()
{
 int dno;
 //clrscr();
 printf("\nEnter the decimal number:");
 scanf("%d",&dno);
 printf("\nBinary equivalent:" );
 binary(dno);
 getch();
 }
void binary(int n)
{
 int q,r;
 if (n==0)
  return;
 r=n%2;
 q=n/2;
 binary(q);
 printf("%d",r);
 }
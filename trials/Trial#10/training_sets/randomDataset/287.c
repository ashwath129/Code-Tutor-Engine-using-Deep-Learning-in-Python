//#include<stdio.h>
 
void main()
{
unsigned int num, mask=32768;
printf("Enter Decimal Number : ");
scanf("%u",&num);
printf("Binary Eqivalent : ");
 
while(mask > 0)
   {
   if((num & mask) == 0 )
         printf("0");
   else
         printf("1");
  mask = mask >> 1 ;  // Right Shift
   }
}

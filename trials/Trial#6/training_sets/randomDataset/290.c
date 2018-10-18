//#include<stdio.h>
//#include<math.h>
void main()
{
long int num;
 long int rem[50],i=0,length=0;
 printf("Enter the decimal number : ");
 scanf("%ld",&num);
 while(num>0)
 {
 rem[i]=num%8;
 num=num/8;
 i++;
 length++;
 }
printf("nOctal number : ");
     for(i=length-1;i>=0;i--)
             printf("%ld",rem[i]);
}

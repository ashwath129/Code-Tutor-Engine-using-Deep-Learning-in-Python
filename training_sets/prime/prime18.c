//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
 
void main()
{
 int M, N, i, j, flag, temp, count = 0;
 
 printf("Enter the value of N\n");
 scanf("%d",&N);

  for (j=2; j<=i/2; j++)
  {
   if( (i%j) == 0)
   {
    flag = 1;
    break;
   }
  }
  if(flag == 0)
  {
   printf("prime");
  }
 	else
 		printf("not prime");
}

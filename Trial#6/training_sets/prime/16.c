#include <stdio.h>

#include <math.h>

void main()

{

        int num,m,n,d; 

        clrscr();

        printf("Enter the Range Between m,n ");

        scanf("%d%d", &m,&n);

       for (num = m; num <= n; num++)

            {

               for(d = 2; d < num; d++)

                {

                   if (num % d == 0)

                      break;

                }

                   if (d == num)

                      printf("%d ", num);

            }

                                     getch();

} 
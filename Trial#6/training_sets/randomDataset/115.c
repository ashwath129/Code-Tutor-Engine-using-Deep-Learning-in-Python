//#include <stdio.h>
main()
{
 int val;
 int status = 0;
 char inbuf[133];
 while (status < 1)
 {
 printf("Enter an integer: ");
gets(inbuf); /* reads in one line of characters from the standard input */
status = sscanf(inbuf, "%d", &val); /* uses string as input to scanf-type function */
 if (status == 0)
 printf("That was not an integer!\n");
 }
 printf("The integer entered was %d.\n", val);
}

//#include <stdio.h>
main()
{
 int divisor, dividend, quotient, remainder;
 int valid_input = 0;
 char inbuf[133];
 /* get the divisor and the dividend */
 while (valid_input < 1)
 {
 printf("Enter the dividend (the number to be divided): ");
 gets(inbuf);
 valid_input = sscanf(inbuf, "%d", &dividend);
 }
 valid_input = 0; /* reset the flag */
 while (valid_input < 1)
 {
 printf("Enter the divisor (the number to divide by): ");
 gets(inbuf);
 valid_input = sscanf(inbuf, "%d", &divisor);
 /* check for an attempt to divide by zero */
 if (divisor == 0)
 {
 printf("Division by zero is not allowed.\n");
 valid_input = 0;
 }
 }
 /* perform the division */
 quotient = dividend / divisor; /* integer division yields only the quotient */
remainder = dividend % divisor; /* % is the modulo operator - yields the remainder */
 /* print the results */
 printf("%d / %d = %d and %d/%d\n",
 dividend, divisor, quotient, remainder, divisor);
}

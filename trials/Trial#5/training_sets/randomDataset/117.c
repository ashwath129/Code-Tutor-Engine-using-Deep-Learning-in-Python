//#include <stdio.h>
main()
{
 int num, rev = 0;
 int valid_input = 0;
 char inbuf[133];
 /* Get an integer from the user - use gets/sscanf for idiot-proofing */
 while (valid_input < 1)
 {
 printf("Enter an integer: ");
 gets(inbuf);
 valid_input = sscanf(inbuf, "%d", &num);
 }
 /*
 * Reverse the number: multiply rev by ten to shift digits to the left,
 * add the units digit from num, then integer divide num by ten to
 * shift digits to the right.
 */
 while (num != 0)
 {
 rev *= 10; /* same as writing rev = rev * 10; */
 rev += num % 10; /* same as writing rev = rev + (num % 10); */
 num /= 10; /* same as writing num = num / 10; */
 }
 /* Print out the result */
 printf("Reverse number is %d.\n", rev);
}

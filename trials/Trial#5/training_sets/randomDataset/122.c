//#include <stdio.h>
main()
{
 float num, sum = 0.0;
 int n = 0;
 /* The the user what to do... */
 printf("Let's average a bunch of numbers\n");
 printf("Enter 'quit' to terminate\n");
 /*
 * Use comma expression within the while loop expression to prompt, then read, the
 * data. The scanf() function will return 1 if the input is floating-point, and
 * will return either 0 or -1 is the input is not. Assuming correct input...
 */
 while ( printf("Enter value #%d: ", n + 1) , scanf("%f", &num) == 1 )
 {
 sum += num;
 n++;
 }
 /* Display the result */
 printf("Average is %f\n", sum / (float) n );
}

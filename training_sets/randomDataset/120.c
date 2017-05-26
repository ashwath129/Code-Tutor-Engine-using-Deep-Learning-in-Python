//#include <stdio.h>
/*
 * The following constant is used to declare the size of the integer array.
 * If the size later changes, then only the define statement needs to be edited
 * instead of going all throughout the source code.
 */
#define SIZE 10
main()
{
 int i,
 sum = 0,
 numbers[SIZE]; /* note that the array index range is from 0 to SIZE-1 */
 char letters[99] = "The average of the integers entered is "; /* legal only here... */
 float result;
 /* get some numbers for the array */
 printf("Let's average %d integers, shall we?\n\n", SIZE);
 for (i = 0; i < SIZE; i++) /* initialize i to 0 */
{ /* LOOP: check here to see if i is less than SIZE */
 printf("Enter integer #%d: ", i+1); /* execute statement body if it is true */
 scanf("%d", &numbers[i]);
 } /* do the update (i++) then jump back to LOOP */
 /* calculate the average */
 for (i = 0; i < SIZE; i++)
 sum += numbers[i];
 result = (float) sum / (float) SIZE;
 /* print out the text string the hard way, then display the result */
 i = 0;
 while (letters[i])
 printf("%c", letters[i++]);
 printf("%f\n", result);
}

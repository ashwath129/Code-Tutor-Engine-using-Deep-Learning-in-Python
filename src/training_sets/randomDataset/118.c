//#include <stdio.h>
//#include <stdlib.h> /* for the rand() function */
//#include <limits.h> /* for the INT_MAX value */
/*
 * define RAND_MAX constant as largest positive value of type int
 * note that this is not defined on some systems, so check to see if it’s there...
 */
#ifndef RAND_MAX
#define RAND_MAX INT_MAX
#endif
main()
{
 int ran1, ran2; /* variables used for the random number */
 int die1, die2; /* variables that will hold final results */
 int seed; /* seed value for random number */
 /*
 * get random number seed from user - later we’ll learn better methods
 * for getting seed values automatically.
 */
 printf("Enter an integer: ");
 scanf("%d", &seed);
 srand(seed);
 /* get the random numbers: range of returned integer is from 0 to RAND_MAX */
 ran1 = rand();
 ran2 = rand();
 if (ran1 == RAND_MAX) /* done to insure that ran1 / RAND_MAX is < 1 */
 ran1--;
 if (ran2 == RAND_MAX)
 ran2--;
 /* convert the integer range [0,RAND_MAX) to [1,6] - use int cast to truncate result */
 die1 = (int) ( 6.0 * ((float) ran1 / (float) RAND_MAX) + 1 );
 die2 = (int) ( 6.0 * ((float) ran2 / (float) RAND_MAX) + 1 );
 /* print the results of the throw */
 printf("You have rolled a %d and a %d.\n", die1, die2);
}

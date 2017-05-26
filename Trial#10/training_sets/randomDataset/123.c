//#include <stdio.h>
//#include <ctype.h>
main()
{
 unsigned long int num_letters = 0;
 unsigned long int letter[26];
 int i;
 char ch;
 /* explicitly initialize the array (don't trust compilers to implicitly set values!) */
 for (i = 0; i < 26; i++)
 letter[i] = 0;
 /* read in characters */
 while ( (ch = getchar()) != EOF )
 if (isalpha(ch)) /* increase the counts if we have a letter */
 {
 num_letters++; /* increase total letter count */
 if (islower(ch)) /* convert to upper case */
 ch = toupper(ch);
 letter[ch-'A']++; /* increase specific letter count by converting ch to */
 /* proper array range of 0-25 */
 }
 /* print out the results */
 printf("\nTotal number of letters: %ld\n", num_letters);
 printf("\nFrequency:\n");
 for (i = 0; i < 26; i++)
 printf("'%c': %6.3f%%\n", 'A' + i,
 100.0 * (float) letter[i] / (float) num_letters);
}

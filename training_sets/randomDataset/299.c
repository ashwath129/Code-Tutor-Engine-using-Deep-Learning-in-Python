//#include<stdio.h>
//#include<stdlib.h>
//#include<ctype.h>
 
/*low implies that position of pointer is within a word*/
#define low 1
 
/*high implies that position of pointer is out of word.*/
#define high 0
 
void main() {
   int nob, now, nod, nov, nos, pos = high;
   char *str;
   nob = now = nod = nov = nos = 0;
 
   printf("Enter any string : ");
   gets(str);
 
   while (*str != '\0') {
 
      if (*str == ' ') {
         // counting number of blank spaces.
         pos = high;
         ++nob;
      } else if (pos == high) {
         // counting number of words.
         pos = low;
         ++now;
      }
 
      if (isdigit(*str)) /* counting number of digits. */
         ++nod;
      if (isalpha(*str)) /* counting number of vowels */
         switch (*str) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
               ++nov;
               break;
         }
 
      /* counting number of special characters */
      if (!isdigit(*str) && !isalpha(*str))
         ++nos;
      str++;
   }
 
   printf("\nNumber of words  %d", now);
   printf("\nNumber of spaces %d", nob);
   printf("\nNumber of vowels %d", nov);
   printf("\nNumber of digits %d", nod);
   printf("\nNumber of special characters %d", nos);
}

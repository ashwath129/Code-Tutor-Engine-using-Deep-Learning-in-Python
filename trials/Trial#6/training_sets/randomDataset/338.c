//#include<stdio.h>
//#include<string.h>
 
void main() {
   char str[10];
   char ch;
	int i, j = 0;
   int size;
   char ch1;
   char str1[10];
 
   printf("\nEnter the string : ");
   gets(str);
 
   printf("\nEnter character which you want to delete : ");
   scanf("%ch", &ch);
 
   size = strlen(str);
 
   for (i = 0; i < size; i++) {
      if (str[i] != ch) {
         ch1 = str[i];
         str1[j] = ch1;
         j++;
      }
   }
   str1[j] = '\0';
 
   printf("\ncorrected string is : %s", str1);
}

//#include<stdio.h>
//#include<string.h>
 
int main() {
   char str1[100];
   char str2[100];
   char str3[100];
   int len;
 
   printf("\nEnter the String 1 : ");
   gets(str1);
 
   printf("\nEnter the String 2 : ");
   gets(str2);
 
   strcpy(str3, str1);
   strcat(str3, str2);
 
   printf("\nConcated String : %s", str3);
 
   return (0);
}

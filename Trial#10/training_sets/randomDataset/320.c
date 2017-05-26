//#include<stdio.h>
//#include<string.h>
 
int main() {
   char *string = "Pritesh Taral";
 
   printf("\nString before to strlwr : %s", string);
 
   strlwr(string);
   printf("\nString after strlwr : %s", string);
 
   return (0);
}

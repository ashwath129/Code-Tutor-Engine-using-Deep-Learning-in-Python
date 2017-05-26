//#include<stdio.h>
 
void main() {
   char str[20];
   int count=0;
   
   printf("\nEnter any string : ");
   gets(str);
   
   while (*p != '\0') {
      count++;
      p++;
   }
   printf("The length of the given string %s is : %d", str, count);
}

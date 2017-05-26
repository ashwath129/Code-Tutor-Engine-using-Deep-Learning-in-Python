//#include<stdio.h>
 
int main() {
   char ch;
 
   printf("\nEnter The Character : ");
   scanf("%c", &ch);
 
   if (ch >= 'A' && ch <= 'Z') {
      printf("Character is uppercase Letters");
   } else if (ch >= 'a' && ch <= 'z') {
      printf("Character is Not Lowercase Letters");
   } else {
      printf("Non alphabet character");
   }
 
   return(0);
}

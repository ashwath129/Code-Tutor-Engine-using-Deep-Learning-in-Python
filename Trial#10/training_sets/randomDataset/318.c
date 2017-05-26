//#include<stdio.h>
//#include<stdlib.h>
 
int main() {
   int num;
   char marks[3];
 
   printf("Please Enter Marks : ");
   scanf("%s", marks);
 
   num = atoi(marks);
   printf("\nMarks : %d", num);
 
   return (0);
}

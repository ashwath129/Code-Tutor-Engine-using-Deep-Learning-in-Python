//#include<stdio.h>
 
int main() {
   int i, j, mat[10][10], row, col;
   int sum = 0;
 
   printf("\nEnter the number of Rows : ");
   scanf("%d", &row);
 
   printf("\nEnter the number of Columns : ");
   scanf("%d", &col);
 
   //Accept the Elements in Matrix
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         printf("\nEnter the Element mat[%d][%d] : ", i, j);
         scanf("%d", &mat[i][j]);
      }
   }
 
   //Addition of all Elements
   for (i = 0; i < row; i++) {
      for (j = 0; j < col; j++) {
         sum = sum + mat[i][j];
      }
   }
 
   //Print out the Result
   printf("\nSum of All Elements in Matrix : %d", sum);
   return (0);
}

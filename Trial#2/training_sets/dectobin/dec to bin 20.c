#include<stdio.h>
struct binary {
       int num;
       struct binary *next;
       };
struct binary* add( struct binary **curr, int n)
 {
  
   struct binary *temp;
   temp=(struct binary *)malloc(sizeof(struct binary));
   temp->num=n;
   temp->next=*curr;
   return temp;
      
 }
int main()
{
     int number, binary_num;
     struct binary *head= NULL;
     printf("ENTER A DECIMAL NUMBER  :   ");
     scanf("%d",&number);
     
     while(number>0)
     {
     binary_num=number%2;
     head =add(&head,binary_num);
     number/=2;
     }
  printf("EQUIVALENT BINRY NUMBER IS   :   ");  
  for(;head!=NULL;head=head->next)
     printf("%d",head->num);


}








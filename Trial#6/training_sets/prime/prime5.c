//#include<stdio.h>
int main()
{
 int num,n,div,p=1;
 printf("Enter any number: ");
 scanf("%d", &n);
  for(div=2; div<n; div++)
  {
   if(n%div==0)
   {
     p=0;
     break;
   }
  }
  if(p==1)
  	printf("prime");
  else
  	printf("composite");
 return 0;
}

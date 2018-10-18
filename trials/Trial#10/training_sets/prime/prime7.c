//#include<stdio.h>
void main()
{
     int n,i,ct=0,rd=0;

     printf("Enter any number \n");
     scanf("%d",&n);

     for(i=2;i<n;i++)
     {
             rd=n%i;
             if(rd==0)
             {
                     ct=1;
                     break;
             }
     }

     if(ct==0)
     {
            printf("\n %d is prime number",n);
     }
     else
     {
            printf("\n %d is not prime number",n);
     }
}

//#include<stdio.h>
void main()
{
	int n,rem;
    printf("\nEnter a number : ");
    scanf("%d",&n);
    rem = n%9;
    if(n==0)
	{
      	printf("\nSingle digit result is 0");
    }
    else
    {
    	if(rem==0)
    	    printf("\nSingle digit result is 9");
        else
    	    printf("\nSingle digit result is %d",rem);
   }
}

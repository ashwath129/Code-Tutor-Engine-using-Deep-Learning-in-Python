//#include<stdio.h>
void main()
{
	long int n;
	int a,x=0,sum=0;
	printf("enter a long digit no.\n");
  	scanf("%ld",&n);
	for(;n>0;)
    {
    	a=n%10;
    	n=n/10;
     	x=x+a; 
    } 
  	if(x<10)
   	{ 
   		sum=x;
      	printf("sum=%d",x);
    }   
   	star:
   	if(x>9)
    { 
    	a=x%10;
     	x=x/10;
     	sum=sum+x;
   		if(sum>9)
     	{ 
     		x=sum;
       		sum=0;
     		goto star;
     	}
   	}
   	printf("sum of the given num=%d",sum);
}

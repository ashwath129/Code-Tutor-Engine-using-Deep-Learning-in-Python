//#include <stdio.h>
//#include<math.h>
int main() 
{
	int a,l,len,sum=0,temp,temp1;
	scanf("%d",&a);
	l=floor (log10 (abs (a))) + 1;
	printf("length is %d",l);
	temp=a;
	while(temp!=0)
	{
		a=temp%10;
	  	temp=temp/10;
	  	sum=sum+a;
	}
	int len1=floor(log10(abs(sum)))+1;
	temp1=sum;
	int com=0;
	while(temp1!=0)
	{
		sum=temp1%10;
        temp1=temp1/10;
        com=com+sum;
	}
	printf("\n final answer is \t %d",com);
	return 0;
}

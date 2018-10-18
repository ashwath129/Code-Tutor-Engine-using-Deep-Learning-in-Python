#include <stdio.h>
#include <math.h>
 
void sieve_method(int limit, int arr[])
{
    	int m, n;
    	for(m = 0; m < limit; m++)
      {
		arr[m] = 1; 
	}
    	arr[0] = 0, arr[1] = 0; 
    	for(m = 2; m < sqrt(limit); m++)
	{ 
        	for (n = m*m; n < limit; n = n + m)
		{
            		arr[n] = 0;	
		}
	}
}
 
int main()
{
    	int count, limit;
	printf("\nEnter The Limit:\t");
	scanf("%d", &limit);
    	int arr[limit];
    	sieve_method(limit, arr);
	printf("\n");
    	for (count = 0; count < limit; count++)
      {
		if (arr[count] == 1)
        	{
			printf("%d\t", count);
		}
	}
	printf("\n");
	return 0;
}
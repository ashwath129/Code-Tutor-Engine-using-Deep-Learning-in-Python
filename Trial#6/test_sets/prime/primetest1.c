//#include <stdio.h>
int main()
{
	int n, i;
	scanf("%d", &n);
	for(i=0; i<=n/2; i++)
	{
		if(n%2==0)
		{
			printf("Not prime");
			return 0;
		}
	}
	printf("Prime");
	return 0;
}

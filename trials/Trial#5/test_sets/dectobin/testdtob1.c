//#include <stdio.h>
int main()
{
	int n, bin[100], size=0, i, temp;
	printf("Enter the decimal number");
	scanf("%d", &n);
	while(n)
	{
		bin[size++] = n%2;
		n/=2;
	}
	for(i=0; i<size/2; i++)
	{
		temp = bin[i];
		bin[i] = bin[size-i-1];
		bin[size-i-1] = temp; 
	}
	printf("\n");
	for(i=0; i<size;i++)
		printf("%d", bin[i]);
	return 0;
}

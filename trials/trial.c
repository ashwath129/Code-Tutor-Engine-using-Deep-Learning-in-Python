main()
{
	int n, sum, x;
	scanf("%d", &n);
	x=n;
	sum=n;
	while(sum>9)
	{
		x=sum;
		sum=0;
		while(x>0)
		{
			sum+=x%10;
			x=x/10;
		}
	}
	printf("Digit sum of %d is %d\n", n, sum);
}

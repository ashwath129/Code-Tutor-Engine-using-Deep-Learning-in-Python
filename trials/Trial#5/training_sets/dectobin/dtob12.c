//#include<stdio.h>
int i=0,bin[100];
void main()
{
    int j=0;
   	printf("\n PLEASE ENTER THE VALUE IN DECIMAL: ");
    scanf("%d",&j);
    for(i=0;j>0;i++)
    {
        bin[i]=j%2;
        j=j/2;
    }
    i--;
    printf("\nDECIMAL TO BINARY CONVERSION IS \t");
    for(i;i>=j;i--)
        printf("%d",bin[i]);
}

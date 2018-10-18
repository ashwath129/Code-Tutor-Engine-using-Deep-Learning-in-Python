#include <stdio.h>
#include <stdlib.h>
 
char *int_to_binary(int);
char b[80];
int main(void)
{                                           // Call function int_to_binary to print a number in binary
    int x=0;
    char *ptr;
 
    if(setvbuf(stdout, NULL, _IONBF,0))
    {
        perror("failed to change the buffer of stdout");
        return EXIT_FAILURE; //clears buffer
    }
 
    printf("This program will convert the users input from decimal to binary.\n");
    printf("Enter a decimal number: ");
    scanf("%d",&x);
    ptr = int_to_binary(x);
    //printf("%s\n", int_to_binary(x));
    return 0;
}
 
char *int_to_binary(int x)
{
    int i;
    for(i=31; i>=0; i--)
    {
        b[i]= x%2;
        x/=2;
    }
    b[33]='\0';
    for(i=0; i<=31;i++)
        printf("%d",b[i]); 
    return b;
}
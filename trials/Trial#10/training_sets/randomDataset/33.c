//#include <stdio.h>
int main()

{

    int a, b, result, temp=0;

 

    printf("Enter two numbers to find their product: ");

    scanf("%d%d", &a, &b);

    while (b != 0)

    {

        temp += a;

        b--;

    }


    printf("Product is %d\n", temp);

    return 0;

}

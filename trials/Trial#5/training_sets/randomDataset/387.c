
//#include <stdio.h>

 

int main()

{

    float height, width;

    float area;

 

    printf("Enter height and width of the given triangle:\n ");

    scanf("%f%f", &height, &width);

    area = 0.5 * height * width;

    printf("Area of right angled triangle is: %.3f\n", area);

    return 0;

}

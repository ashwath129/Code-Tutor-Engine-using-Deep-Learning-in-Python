
//#include <stdio.h>

 

int main()

{

    int year, yr;

 

    printf("Enter the year ");

    scanf("%d", &year);

    yr = year % 100;

    printf("Last two digits of year is: %02d", yr);

    return 0;

}

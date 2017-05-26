    #include<stdio.h>
    #include<conio.h>
    void decimal_to_binary(unsigned long int);
    int main(){
                 unsigned long int number;
                 clrscr();
                 printf("Enter a big decimal number : ");
                 scanf("%lu",&number);
                 decimal_to_binary(number);
                 getch();
    return(0);
    }
    void decimal_to_binary(unsigned long int n){
                 unsigned long int range=2147483648;
                 printf("\n The Binary Eqivalent is ");
                 xy:
                 if(range > 0)
                 {
                 if((n & range) == 0 ){
                 range = range >> 1 ;
                 goto xy; }
                 else
                 while(range>0){
                 if((n & range) == 0 )
                 printf("0");
                 else
                 printf("1");
                 range = range >> 1 ;
                 }
                 }
    }
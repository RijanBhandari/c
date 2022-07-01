// Program to get two numbers and count the digits of two numbers using single function
#include<stdio.h>
#include<math.h>
int counter(int);
void main(){
int a,b,r,c;
printf("Enter two numbers");
scanf("%d%d",&a,&b);
r = counter(a);
printf("The number of digits in %d is %d",a,r);
c = counter(b);
printf("\nThe number of digits in %d is %d",b,c);
}

int counter(int c){
    int len;
    len = log10(c)+1;
    return len;
}

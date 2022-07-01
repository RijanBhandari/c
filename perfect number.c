//program to check wheather the given number is perfect number or not using function
#include<stdio.h>
int perfectck(int);
void main (){
int a,r;
printf("enter a number");
scanf("%d",&a);
r = perfectck(a);
if (r == a)
printf("perfect number");
else
printf("not a perfect number");
}

int perfectck(int a){
int sum = 0, i,fact=1;
for (i=1;i<=a/2;i++){
    if (a % i == 0){
        fact = i;
    }
    sum = sum + fact ;
}
return sum;
}

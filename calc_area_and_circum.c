//calculate the area and circumference using pass by reference.
#include<stdio.h>
void calc(int,float*,float*);
#define pi 3.14
void main(){
int r;
float A,C;
printf("Enter radius of circle");
scanf("%d",&r);
calc(r,&A,&C);
printf("The area is %f\n",A);
printf("The circumference is %f",C);
}

void calc(int r,float *A,float *C){
    *A = pi * r * r;
    *C = 2 * pi * r;
}

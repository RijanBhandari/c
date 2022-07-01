#include<stdio.h>
float smaller(float,float,float);
void main(){
float a,b,c,r;
printf("Enter decimal point numbers a,b and c.");
scanf("%f%f%f",&a,&b,&c);
r = smaller(a,b,c);
printf("The smallest decimal point number is %f",r);
}

float smaller(float a,float b,float c){
if (a<b && a<c)
return a;
else if(b<c && b<a)
return b;
else
return c;
}

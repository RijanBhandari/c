#include<stdio.h>
#include<math.h>
int sum(int);
void main()
{
    int n,s;
    printf("Enter an interger: ");
    scanf("%d",&n);
    s=sum(n);
    if (n == s)
    printf("\nArmstrong number.");
    else
    printf("\n Not an armstrong number");
}

int sum(int n){
{
    int d,s=0,len;
    len = log10(n)+1;
    while(n!=0){
        d = n%10;
        s = s + pow(d,len);
        n = n / 10;
    }

return s;
}
}

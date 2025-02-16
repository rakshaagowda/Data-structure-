#include <stdio.h>
int gcd(int a,int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a>b)
        gcd(a%b,b);
    else
        gcd(a,b%a);
}
int main()
{
	int m,n;
    scanf("%d %d",&m,&n);
    printf(" gcd: %d",gcd(m,n));
	return 0;
}

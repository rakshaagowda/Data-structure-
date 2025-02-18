//print n number from n-1 using recursion
#include <stdio.h>


int print(int n){
    
    if(n==0)
        return 0;
    else{
        printf("%d ",n);
        return print(n-1);
    }
}
int main()
{
	int n;
    scanf("%d",&n);
    printf("%d",print(n));
	return 0;
}
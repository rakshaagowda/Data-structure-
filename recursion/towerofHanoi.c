//Tower of Hanoi
#include <stdio.h>
void tower(int n,char beg,char end,char aux){
    if(n==1){
        printf("Move disk 1 from %c to %c\n",beg,end);
        return ;
    }
    tower(n-1,beg,aux,end);
    printf("Move disk %d from %c to %c\n",n,beg,end);
    tower(n-1,aux,end,beg);
}
int main()
{
	int n;
    scanf("%d",&n);
    tower(n,'A','C','B');
	return 0;
}

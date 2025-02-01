#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct Stack{
    int stk[MAX];
    int top;
}S;

void push(int X){
    if(S.top==MAX-1){
        printf("overflow");
        
    }
    else{
        S.stk[++S.top]=X;
    }
} 

void pop(){
    if(S.top==-1){
        printf("stack underflow");
    }
    else{
        printf("popped element is %d\n",S.stk[S.top]);
        S.top--;
    }
}

void display(){
    if(S.top==-1){
        printf("stack underflow");
    }
    else{
        for(int i=S.top;i>0;i--){
            printf("%d",S.stk[i]);
            printf("\n");
        }
    }
}

void peek(){
        if(S.top==-1){
        printf("stack underflow");
    }
    else{
        printf("\npeeking%d\n",S.stk[S.top]);
    }
}
void main(){
    int data;
    int ch;
    do{
        printf("\nENter\n1.push\n2.pop\n3.peek\n4.display\n0.exit");
        printf("\nenter your choice: ");
        scanf("%d",&ch);
    switch(ch){    
    case 1:printf("enter and element to push: ");
            scanf("%d",&data);
            push(data);
            break;
    case 2:pop();
            break;
    case 3:peek();
            break;
    case 4:display();
            break;
    case 0: printf("exiting!");
            break;
    default: printf("invalid choice");
            break;
        }
    }while(ch!=0);
}
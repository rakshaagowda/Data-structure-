#include <stdio.h>
#include <string.h>\
#include <ctype.h>
#include <stdlib.h>

int stackprec(char symbol){
    switch(symbol){
        case '+':
        case '-':return 2;
        case '*':
        case '/':
        case '%':return 4;
        case '^':
        case '$':return 5;
        case '(':return 0;
        case '#':return -1;
        default :return 8;
        
    }
}




int inprec(char symbol){
    switch(symbol){
        case '+':
        case '-':return 1;
        case '*':
        case '/':
        case '%':return 3;
        case '^':
        case '$':return 6;
        case '(':return 9;
        case ')':return 0;
        default :return 7;
        
    }
}

void infixtopostfix(char infix[],char postfix[]){
   char S[30];
   int i=0,j=0;
   int top=-1;
   S[++top]='#';
   char symbol;
   for(i=0;i<strlen(infix);i++){
       symbol=infix[i];
       while(stackprec(S[top])>inprec(symbol)){
           postfix[j++]=S[top--];
       }
       if(stackprec(S[top])!=inprec(symbol)){
           S[++top]=symbol;
           
       }
       else{
           top--;
       }
   }
   while(S[top]!='#'){
       postfix[j]=S[top--];
       j++;
   }
   postfix[j]='\0';
}

void  main()
{
	char infix[30];
    char postfix[30];
    int choice;
    printf("Menu\n1.Enter infix\n2.convert to postfix\n3.exit");
    for(;;){
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\nENter the infix");
                    scanf("%s",infix);
                    break;
            case 2:infixtopostfix(infix,postfix);
                    printf("\npostfix expression is:\n%s\n",postfix);
                    break;
            
            case 3:printf("exiting\n");
                    exit(0);
            default:printf("Invalid choice\n");
                    
        }
    }
}

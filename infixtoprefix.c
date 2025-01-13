#include <stdio.h>
#include <string.h>\
#include <ctype.h>
#include <stdlib.h>

// Function to reverse a string
void reverseString(char str[]) {
    int length = strlen(str); // Get the length of the string
    int start = 0;            // Start index
    int end = length - 1;     // End index
    char temp;                // Temporary variable for swapping

    while (start < end) {
        // Swap characters at start and end
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move start forward and end backward
        start++;
        end--;
    }
}

int stackprec(char symbol){
    switch(symbol){
        case '+':
        case '-':return 1;
        case '*':
        case '/':
        case '%':return 3;
        case '^':
        case '$':return 6;
        case ')':return 0;
        case '#':return -1;
        default :return 8;
        
    }
}



int inprec(char symbol){
    switch(symbol){
        case '+':
        case '-':return 2;
        case '*':
        case '/':
        case '%':return 4;
        case '^':
        case '$':return 5;
        case '(':return 0;
        case ')':return 9;
        default :return 7;
        
    }
}

void infixtoprefix(char infix[],char prefix[]){
   
    char S[30];
   int i=0,j=0;
   int top=-1;
   S[++top]='#';
   char symbol;
   reverseString(infix);
   for(i=0;i<strlen(infix);i++){
       symbol=infix[i];
       while(stackprec(S[top])>inprec(symbol)){
           prefix[j++]=S[top--];
       }
       if(stackprec(S[top])!=inprec(symbol)){
           S[++top]=symbol;
           
       }
       else{
           top--;
       }
   }
   while(S[top]!='#'){
       prefix[j]=S[top--];
       j++;
   }
   prefix[j]='\0';
   reverseString(prefix);
}



void  main()
{
	char infix[30];
    char prefix[30];
    int choice;
    printf("Menu\n1.Enter infix\n2.convert to prefix\n3.exit");
    for(;;){
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\nENter the infix");
                    scanf("%s",infix);
                    break;
            case 2:infixtoprefix(infix,prefix);
                    printf("\nprefix expression is:\n%s\n",prefix);
                    break;
            case 3: printf("exiting\n");
                    exit(0);
            default:printf("Invalid choice\n");
                    
        }
    }
}


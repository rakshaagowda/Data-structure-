#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX 30

char charStack[MAX];
int charTop=-1;
int intStack[MAX];
int intTop=-1;
void pushChar(char c){
    if(charTop== MAX-1){
        printf("Stack overflow");
        return ;
    }
    charStack[++charTop]=c;
    
}
char popChar(){
    if(charTop== -1){
        printf("Stack underflow");
        return '\0';
    }
    return charStack[charTop--];
    
}
char peekChar(){
    if(charTop== -1){
        printf("Stack underflow");
        return '\0';
    }
    return charStack[charTop];
    
}
void pushInt(int x){
    if(intTop== MAX-1){
        printf("Stack overflow");
        return ;
    }
    intStack[++intTop]=x;
    
}

int popInt(){
    if(intTop== -1){
        printf("Stack underflow");
        return 0;
    }
    return intStack[intTop--];
    
}

int precedence(char op){
    switch(op){
        case '^':return 3;
        case '*':
        case '/':
        case '%':return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
    
}

int isOperator(char c){
    if (c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='%'){
        return 1;
    }
    return 0;
}

void infixtopostfix(char* infix,char*postfix){
    int i=0,j=0;
    char c;
    while((c=infix[i++])!='\0'){
    if(isdigit(c)|| isalpha(c)){
        postfix[j++]=c;
    }
    else if(c=='('){
        pushChar(c);
    }
    else if(c==')'){
        while(charTop!=-1 && peekChar()!= '('){
            postfix[j++]=popChar();
        }
        popChar();
    }
    else if(isOperator(c)){
        while(charTop!=-1 && precedence(peekChar())>= precedence(c)){
            postfix[j++]=popChar();
        }
        pushChar(c);
    
    }
    }
    while(charTop!=-1){
        postfix[j++]=popChar();
    }
    postfix[j]='\0';
}

void evaluatePostfix(char* postfix){
    int j=0,final,res;
    char c;
    while((c=postfix[j++])!='\0'){
        if(isdigit(c)){
            pushInt(c-'0');
        }else if(isOperator(c)){
            int val2=popInt();
            int val1=popInt();
            switch(c){
                case '+': pushInt(val1+val2);break;
                 case '-': pushInt(val1-val2);break;
                  case '*': pushInt(val1*val2);break;
                   case '/': pushInt(val1/val2);break;
                    case '%': pushInt(val1%val2);break;
                    case '^': res=powf(val1,val2);
                                pushInt(res);
                                break;
            }
        }
    }
    final=popInt();
    printf("final result: %d",final);
}

int main()
{
        char infix[MAX],postfix[MAX];
        
        printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixtopostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    evaluatePostfix(postfix);
    //printf("Result of evaluation: %d\n", result);
	
	return 0;
}

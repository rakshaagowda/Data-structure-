#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX 30
typedef struct cstack{
char charStack[MAX];
int charTop;
}*cs;



typedef struct istack{
int intStack[MAX];
int intTop;
}*is;



void pushChar(cs S,char c){
    if(S->charTop== MAX-1){
        printf("Stack overflow");
        return ;
    }
    S->charStack[++(S->charTop)]=c;
    
}
char popChar(cs S){
    if(S->charTop== -1){
        printf("Stack underflow");
        return '\0';
    }
    return S->charStack[(S->charTop)--];
    
}
char peekChar(cs S){
    if(S->charTop== -1){
        printf("Stack underflow");
        return '\0';
    }
    return S->charStack[S->charTop];
    
}
void pushInt(is I,int x){
    if(I->intTop== MAX-1){
        printf("Stack overflow");
        return ;
    }
    I->intStack[++(I->intTop)]=x;
    
}

int popInt(is I){
    if(I->intTop== -1){
        printf("Stack underflow");
        return 0;
    }
    return I->intStack[I->intTop--];
    
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

void infixtopostfix(cs S,char* infix,char*postfix){
    int i=0,j=0;
    char c;
    while((c=infix[i++])!='\0'){
    if(isdigit(c)|| isalpha(c)){
        postfix[j++]=c;
    }
    else if(c=='('){
        pushChar(S,c);
    }
    else if(c==')'){
        while(S->charTop!=-1 && peekChar(S)!= '('){
            postfix[j++]=popChar(S);
        }
        popChar(S);
    }
    else if(isOperator(c)){
        while(S->charTop!=-1 && precedence(peekChar(S))>= precedence(c)){
            postfix[j++]=popChar(S);
        }
        pushChar(S,c);
    
    }
    }
    while(S->charTop!=-1){
        postfix[j++]=popChar(S);
    }
    postfix[j]='\0';
}

void evaluatePostfix(is I,char* postfix){
    
    int j=0,final,res;
    char c;
    while((c=postfix[j++])!='\0'){
        if(isdigit(c)){
            pushInt(I,c-'0');
        }else if(isOperator(c)){
            int val2=popInt(I);
            int val1=popInt(I);
            switch(c){
                case '+': pushInt(I,val1+val2);break;
                 case '-': pushInt(I,val1-val2);break;
                  case '*': pushInt(I,val1*val2);break;
                   case '/': pushInt(I,val1/val2);break;
                    case '%': pushInt(I,val1%val2);break;
                    case '^': res=powf(val1,val2);
                                pushInt(I,res);
                                break;
            }
        }
    }
    final=popInt(I);
    printf("final result: %d",final);
}

int main()
{   
    char infix[MAX],postfix[MAX];  
     cs S;
    is I;
    S=(cs)malloc(sizeof(struct cstack));
    I=(is)malloc(sizeof(struct istack));
      
        printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    infixtopostfix(S,infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    evaluatePostfix(I,postfix);
    //printf("Result of evaluation: %d\n", result);
	
	return 0;
}


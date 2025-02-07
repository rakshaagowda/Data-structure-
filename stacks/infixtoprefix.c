
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

void reversestr(char *str){
    int len=strlen(str);
    int i;
    for(i=0;i<len/2;i++){
        char temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }
}

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

void infixtoprefix(cs S,char* infix,char*prefix){
    reversestr(infix);
    int i=0,j=0;
    char c;
    while((c=infix[i++])!='\0'){
    if(isdigit(c)|| isalpha(c)){
        prefix[j++]=c;
    }
    else if(c==')'){
        pushChar(S,c);
    }
    else if(c=='('){
        while(S->charTop!=-1 && peekChar(S)!= ')'){
            prefix[j++]=popChar(S);
        }
        popChar(S);
    }
    else if(isOperator(c)){
        while(S->charTop!=-1 && precedence(peekChar(S))>= precedence(c)){
            prefix[j++]=popChar(S);
        }
        pushChar(S,c);
    
    }
    }
    while(S->charTop!=-1){
        prefix[j++]=popChar(S);
    }
    prefix[j]='\0';
    reversestr(prefix);
}

void evaluatePrefix(is I,char* prefix){
    reversestr(prefix);
    int j=0,final,res;
    char c;
    while((c=prefix[j++])!='\0'){
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
    char infix[MAX],prefix[MAX];  
     cs S;
    is I;
    S=(cs)malloc(sizeof(struct cstack));
    I=(is)malloc(sizeof(struct istack));
      
        printf("Enter an infix expression: ");
    scanf("%s", infix);
    
    infixtoprefix(S,infix, prefix);
    printf("Postfix expression: %s\n", prefix);

    evaluatePrefix(I,prefix);
    //printf("Result of evaluation: %d\n", result);
	
	return 0;
}


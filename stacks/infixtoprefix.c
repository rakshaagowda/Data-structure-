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

void infixtoprefix(char* infix,char*prefix){
    int i=0,j=0;
    char c;
    reverseString(infix);
    for (int k = 0; infix[k] != '\0'; k++) {
        if (infix[k] == '(')
            infix[k] = ')';
        else if (infix[k] == ')')
            infix[k] = '(';
    }
    
    
    while((c=infix[i++])!='\0'){
    if(isdigit(c)|| isalpha(c)){
        prefix[j++]=c;
    }
    else if(c=='('){
        pushChar(c);
    }
    else if(c==')'){
        while(charTop!=-1 && peekChar()!= '('){
            prefix[j++]=popChar();
        }
        popChar();
    }
    else if(isOperator(c)){
        while(charTop!=-1 && precedence(peekChar())>= precedence(c)){
            prefix[j++]=popChar();
        }
        pushChar(c);
    
    }
    }
    while(charTop!=-1){
        prefix[j++]=popChar();
    }
    prefix[j]='\0';
    reverseString(prefix);
}

void evaluatePrefix(char* prefix){
    int j=0,final,res;
    char c;
     reverseString(prefix);
    while((c=prefix[j++])!='\0'){
        if(isdigit(c)){
            pushInt(c-'0');
        }else if(isOperator(c)){
            int val1=popInt();
            int val2=popInt();
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
        char infix[MAX],prefix[MAX];
        
        printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixtoprefix(infix, prefix);
    printf("Postfix expression: %s\n", prefix);

    evaluatePrefix(prefix);
    
	
	return 0;
}

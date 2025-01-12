void postfixevaluate(char postfix[]){
    int i,op1,op2,res;
    int Stack[10];
    char ch;
    int top=-1;
    for(int i=0;i<strlen(postfix);i++){
        ch=postfix[i];
        if(isdigit(ch)){
            Stack[++top]=ch-'0';
        }
        else{
            if(top<1){
                printf("not enough operands\n");
                
            }
            else{
                op2=Stack[top--];
                op1=Stack[top--];
                switch(ch){
                    case '+': res=op1+op2;
                                break;
                    case '-': res=op1-op2;
                                break;
                    case '/': res=op1/op2;
                                break;
                    case '*': res=op1*op2;
                                break;
                    case '%': res=op1%op2;
                                break;
                    default:printf("invalid operator\n");
                }
                Stack[++top]=res;
                }
            }
        }
        printf("Final result=%d\n",Stack[top]);
    }
#include <stdio.h>
#include <stdlib.h>
int size=5;
struct Queue{
    int front, rear;
    int *que;
	
}q;

//typedef struct Queue q;
void enqueue(int val){
    if(q.front==0&&q.rear==size-1){
        printf("queue full\n reallocating memory\n");
        size++;
        q.que=(int *)realloc(q.que,size*sizeof(int));
        
    }
    else{
        if(q.front==-1){
            q.front=0;
            }
        }
    q.rear=(q.rear+1)%size;
    *(q.que+(q.rear))=val;
}

void dequeue(){
    if(q.front==-1){
        printf("empty");
        return;
    }
    else{
        printf("deleted element: %d\n",*(q.que+(q.front)));
        if(q.front==q.rear){
            q.front=q.rear=-1;
            return;
        }
        q.front=(q.front+1)%size;
    }
}

void display(){
    if(q.front==-1){
        printf("empty");
        return;
    }
    if(q.front<=q.rear){
        for(int i=q.front;i<=q.rear;i++){
            printf("%d\t",*(q.que+i));
        }
    }
    else{
        
        for(int i=q.front;i<=size-1;i++){
            printf("%d\t",*(q.que+i));
        }
        for(int j=0;j<=q.rear;j++){
            printf("%d\t",*(q.que+j));
        }
    }
}

int main(){
    int choice,val;
    q.front=q.rear=-1;
    printf("enter size: ");
    scanf("%d",&size);
    q.que=(int *)malloc(size*sizeof(int));
    printf("\nmenu\n1.insert\n2.delete\n3.display\n4.exit");
    for(;;){
        printf("\nenter choicr: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter value: ");
                    scanf("%d",&val);
                    enqueue(val);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("invalid choice");
            
        }
    }
 return 0;   
    
}
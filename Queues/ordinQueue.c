#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct Queue{
    int front;
    int rear;
    int que[SIZE];
};
typedef  struct Queue *Q;

void enqueue(Q q, int val){
    if(q->rear == SIZE-1){
        printf("full");
        return;
        
    }
    if(q->front ==-1){
        q->front=0;
    }
    q->rear++;
    q->que[q->rear]=val;
    
    
}

void dequeue(Q q){
    if(q->front==-1){
        printf("\nsempty");
        return;
    }
    else{
        printf(" delted element : %d\n",q->que[q->front]);
        if(q->front==q->rear){
            q->front=q->rear=-1;
            return;
        }
        q->front++;
    }
    
}

void display(Q q){
    if(q->front==-1){
        printf("empty");
        return;
    }
    for(int i=q->front;i<=q->rear;i++){
        printf("%d\t",q->que[i]);
    }
    printf("\n");
}
int main()
{
        Q q;
        q=(Q)malloc(sizeof(struct Queue));
        q->front=q->rear=-1;
        for(int j=0;j<5;j++)
            enqueue(q,j);
            
        dequeue(q);
        display(q);
	return 0;
}

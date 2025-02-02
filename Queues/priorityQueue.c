#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int size,n;
struct queue{
    int front,rear;
    int *que;
};

typedef struct queue *Q;

void init(Q q){
    q->que=(int*)malloc(size*sizeof(int));
    q->front=q->rear=-1;
}

int isFull(Q q){
    return((q->front==0 && q->rear==size-1)||(q->front==q->rear+1));
}

int isEmpty(Q q){
    return((q->front==-1));
}

void insertFront(Q q,int val){
    if(isFull(q)){
        printf("\nfull\n");
        return ;
    }
    else if(q->front==0){
        q->front=size-1;
    }
    else if(isEmpty(q)){
        q->front=q->rear=0;
    }
    else{
        q->front--;
    }
    *(q->que+(q->front))=val;
}

void insertRear(Q q,int val){
    if(isFull(q)){
        printf("\nfull\n");
        return ; 
    }
    else if(isEmpty(q)){
        q->front=q->rear=0;
    }
    else if(q->rear==size-1){
        q->rear=0;
    }
    else{
        q->rear++;
    }
    *(q->que+(q->rear))=val;
}

void display(Q q){
    if(isEmpty(q)){
        printf("\nempty\n");
        return ;
    }
    int i=q->front;
    while(1){
        printf("|%d|", *(q->que+i));
        if (i == q->rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}

void deleteFront(Q q){
    if(isEmpty(q)){
        printf("\nempty\n");
        return ;
    }
    printf("\ndeleted element: %d\n",*(q->que+(q->front)));
    if(q->front==size -1){
        q->front=0;
    }
    else if(q->front==q->rear){
        q->front=q->rear=-1;
    }
    else{
        q->front++;
    }
}

void deleteRear(Q q){
    if(isEmpty(q)){
        printf("\nempty\n");
        return ;
    }
    printf("\ndeleted element: %d\n",*(q->que+(q->rear)));
    if(q->rear==0){
        q->rear=size-1;
    }
    else if(q->front==q->rear){
        q->front=q->rear=-1;
    }
    else{
        q->rear--;
    }
    
    
}

int main()
{
    Q q;
    int val,choice;
    q=(Q)malloc(sizeof(struct queue));
	printf("enter the initial size of queue: ");
    scanf("%d",&size);
    init(q);
    printf("\nmenu\n1.insert front \n2.insert rear \n3.delete front \n4.delete rear\n5.display\n0.exit");
    for(;;){
        printf("\nenter choicr: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter value: ");
                    scanf("%d",&val);
                    insertFront(q, val);
                    break;
            case 2: printf("enter value: ");
                    scanf("%d",&val);
                    insertRear(q,val);
                    break;
            case 3: deleteFront(q);
                    break;
            case 4:  deleteRear(q);
                    break;
            case 5: display(q);
                    break;
            case 0: exit(0);
            default: printf("invalid choice");
            
        }
    }
    
    
	return 0;
}

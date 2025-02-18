#include <stdio.h>
#define MAX 5

typedef struct{
    int val;
    int priority;
}element;
int size=0;
element queue[MAX];
void insert(int val,int priority){
    if(size>MAX){
        printf("\nfull");
        return ;
        
    }
    queue[size].val=val;
    queue[size].priority=priority;
    size++;
    
    
}
void delete_element(){
    if(size==0){
        printf("\nempty");
        return ;
    }
    int Hindex=0;
    for(int i=1;i<size;i++){
        if(queue[Hindex].priority<queue[i].priority){
            Hindex=i;
        }
    }
    printf("deleted %d and priority %d",queue[Hindex].val,queue[Hindex].priority);
    for(int i=Hindex;i<size-1;i++){
        queue[i]=queue[i+1];
    }
    size--;
}
void display(){
    if(size==0){
        printf("\nempty");
        return ;
    }
    printf("(val,priority)\n");
    for(int i=0;i<size;i++){
        printf("| %d , %d |",queue[i].val,queue[i].priority);
    }
    printf("\n");
}
int main()
{
	insert(10, 2);
    insert(20, 1);
    insert(30, 3);
    insert(40, 4);

    printf("Initial Queue:\n");
    display();

    delete_element();
    printf("Queue after deletion:\n");
    display();
	return 0;
}

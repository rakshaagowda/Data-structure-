#include <stdio.h>
#include <stdlib.h>
int count;
struct node{
    int data;
    struct node *next,*prev;
};
typedef struct node *Node;

Node createnode(int data){
    Node nn=(Node)malloc(sizeof(struct node));
    if(nn==NULL){
        printf("Memory allocation failed\n");
       return nn; 
    }
    nn->next=nn;
    nn->prev=nn;
    nn->data=data;
    
    return nn;
}
void reverse(Node Header){
    if(Header->next==Header||Header->next->next==Header){
        printf("operation not possible ");
        return;
    }
    Node swap, temp=Header;
    do{
        swap=temp->next;
        temp->next=temp->prev;
        temp->prev=swap;
        temp=temp->prev;
        
    }while(temp!=Header);
    
}
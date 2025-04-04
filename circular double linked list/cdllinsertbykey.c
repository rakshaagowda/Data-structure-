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
void insertbykey(Node Header,int key){
    Node nn=createnode(key);
    if(nn== NULL){
        return;
    }
    count++;
    if(Header->next==Header){
        nn->next=Header;
        nn->prev=Header;
        Header->next=nn;
        Header->prev=nn;
        return;
    }
    Node temp=Header->next;
    while(temp!=Header){
        if(temp->data>key){
            
            break;
        }
        temp=temp->next;
    }
    nn->next=temp;
    nn->prev=temp->prev;
    temp->prev->next=nn;
    temp->prev=nn;
}
#include <stdio.h>
#include <stdlib.h>
int count;
struct node{
    int data;
    struct node *next,*prev;
};
typedef struct node *Node;
int n;
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

void insertFront(Node Header,int data){
  Node nn=create(data);
 
 
  if(Header->next==Header){
      Header->prev=nn;
  }
   nn->next=Header->next;
   Header->next->prev=nn;
  nn->prev=Header;
   Header->next=nn;
   n++;
}
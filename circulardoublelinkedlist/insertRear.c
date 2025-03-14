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
void insertRear(Node Header,int data){
  Node nn=create(data);
  if(Header->next==Header){
      Header->next=nn;
  }
  nn->next=Header;
  Header->prev->next=nn;
  nn->prev=Header->prev;
  Header->prev=nn;
  n++;
}
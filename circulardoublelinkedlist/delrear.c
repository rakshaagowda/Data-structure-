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
void deleterear(Node Header){
  if(Header->next==Header){
      return;
  }
  Header->prev=Header->prev->prev;
  Header->prev->next= Header;
  n--;
}
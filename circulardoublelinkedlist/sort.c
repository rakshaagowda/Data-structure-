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
void sort(Node Header){
  if(Header->next==Header||Header->next->next==Header){
      printf("operation not possible");
      return ;
  }
  for(Node i=Header->next;i->next!=Header;i=i->next){
      for(Node j=i->next;j!=Header;j=j->next){
          if(i->data>j->data){
              int swap=i->data;
              i->data=j->data;
              j->data=swap;
          }
      }
  }
}
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
void insertbypos(Node Header,int data,int pos){
    Node nn=createnode(data);
    if(pos<1||pos>count+1){
        printf("invalid pos\n");
        return;
    }
    Node temp=Header->next;
    int i=1;
    while(i<pos-1){
        i++;
        temp=temp->next;
    }
    nn->next=temp->next;
    nn->prev=temp;
    temp->next->prev=nn;
    temp->next=nn;
    count++;  
}
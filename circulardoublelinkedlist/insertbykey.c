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
void insertbykey(Node Header,int data){
  Node nn=createnode(data);
  Node temp=Header->next;
  while(temp->next->data<data){
    temp=temp->next;
  }
  nn->prev=temp;
  nn->next=temp->next;
  temp->next->prev=nn;
  temp->next=nn;
  

}
int main(){


  return 0;
}

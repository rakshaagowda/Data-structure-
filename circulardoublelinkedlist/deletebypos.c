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
void deletebypos(Node Header,int pos){
  if(Header->next==Header){
      printf("\nEmpty list\n");
      return ;
  }
  if(pos<1||pos>n){
      printf("invalid pos ");
      return;
  }
  if(pos==1){
      Node ND=Header->next;
      Header->next->next->prev=Header;
      Header->next=Header->next->next;
      free(ND);
      return ;
  }
  int i=1;
  Node temp=Header->next;
  while(i<pos-1){
      temp=temp->next;
      i++;
  }
  Node ND=temp->next;
  temp->next->next->prev=temp;
  temp->next=temp->next->next;
  free(ND);
  n--;
      
}
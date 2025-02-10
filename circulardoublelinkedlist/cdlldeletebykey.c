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
void deletebykey(Node Header,int key){
    if(Header->next==Header){
        printf("\nempty\n");
        return;
    }
    int found=0, i=1;
    Node temp=Header->next;
    while(temp!=Header){
        if(temp->data==key){
            found=1;
            break;
        }
        temp=temp->next;
        i++;
    }
    if(found==0){
        printf("key not found");
        return ;
    }
    else{
       printf("\nkey found at pos %d\n",i);
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        count--;
        Header->data=count;
    }
}
int main(){
    int choice,data;




    return 0;
}
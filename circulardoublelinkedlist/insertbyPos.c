#include <stdio.h>
#include <stdlib.h>
int count;
struct node{
    int data;
    struct node *next,*prev;
};
typedef struct node *Node;
int n;
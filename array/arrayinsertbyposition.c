//insert an element by position in the sorted array 
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int n;void insertbypos(int* arr,int pos, int key){
    n++;
    if(n>MAX){
        arr=(int *)realloc(arr,n*sizeof(int));
        
    }
    if(pos<1||pos>n){
        printf("invalid position");
        return;
    }
    for(int i=n-1;i>=pos-1;i--){
        *(arr+i)=*(arr+(i-1));
    
    }
    *(arr+(pos-1))=key;
}
//delete an element by position
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int n;
void deletebypos(int* arr,int pos){
    if(pos<1||pos>n){
        printf("invalid pos");
        return;
    }
    printf("deleted %d\n",*(arr+(pos-1)));
    n--;
    for(int i=pos-1;i<n;i++){
        *(arr+i)=*(arr+(i+1));
    }
}
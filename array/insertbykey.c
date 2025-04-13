#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int n;
void read(int* ptr){
  printf("enter %d elements:",n);
  for(int i=0;i<n;i++){
      scanf("%d", (ptr+i));
      
      }
  }

  
void display(int* ptr){
for(int i=0;i<n;i++){
    printf("%d\t",*(ptr+i));
}
}

void insertbykey(int* ptr,int key,int pos){
  ptr=(int*)realloc(ptr,(n+1)*sizeof(int));    
  for(int i=n;i>pos;i--){
      *(ptr+i)=*(ptr+(i-1));
  }       
  
  *(ptr+(pos-1))=key;
  n++;
} 
int main(){

  int *ptr;
  int i,pos,key;
  printf("\nEnter the initial number of elements: "); 
  scanf("%d",&n);
  ptr=(int*)malloc(n*sizeof(int));  
  read(ptr);
  display(ptr);
  printf("\nEnter the key to be inserted: "); 
  scanf("%d",&key);
  printf("\nEnter the position to be inserted: "); 
  scanf("%d",&pos);
  insertbykey(ptr,key,pos);
  display(ptr);
  return 0;
}  
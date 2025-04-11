#include<stdio.h>
int n,pos,key;
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
  void deletebypos(int* ptr,int pos){
    printf("deleted key is %d",*(ptr+(pos-1)));
    for(int i=pos-1;i<n-1;i++){
        *(ptr+i)=*(ptr+(i+1));
    }
    n--;
  }
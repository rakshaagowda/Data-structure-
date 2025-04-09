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
void deletebykey(int* ptr,int key){
  int flag=0;
  for(int i=0;i<n;i++){
      if(*(ptr+i)==key){
          flag=1;
          pos =i;
          break;
          }
      
      }
      
      if(flag == 0){
          printf("\nkey not found");
          return ;
          }
      else{
          for(int i=pos;i<n-1;i++){
              *(ptr+i)=*(ptr+(i+1));
              
          }
          n--;
      }
  }

  int main(){

    int *ptr;
    int i;
    printf("\nenter the number of elements: ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    read(ptr);
    display(ptr);
    printf("\nenter the key to be deleted: ");
    scanf("%d",&key);
    deletebykey(ptr,key);
    display(ptr);


    return 0;
  }
//search an element and insert
#include<stdio.h>
#include<stdlib.h>
int size;
int n,pos,key;
//i don wanna lose you
//i don wanna lose you

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

void searchInsert(int *ptr,int key){
  int found=0;
  
  for(int i=0;i<n;i++){
    if(*(ptr+i)==key){
      pos=i+1;
      found=1;
      break;
    }
  }
  if(!found){
    n++;
    if(n>size){
      size++;
      ptr=(int*)realloc(ptr,size*sizeof(int));
    }
    for(int i=n-1;i>0;i--){
      *(ptr+i)=*(ptr+i-1);
    }
    *(ptr+0)=key;
    return ;
  }
  //key present

}

int main()
{
    int *ptr;
    //int key,pos;
    printf("\nenter the number of elements: ");
    
    scanf("%d",&n);
    size=n;
    ptr=(int*)malloc(n*sizeof(int));
    read(ptr);
    display(ptr);
    printf("\nenter the key to be inserted: ");
    scanf("%d",&key);
    searchInsert(ptr,key);
    display(ptr);

  return 0;
}
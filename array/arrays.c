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

void insertbypos(int* ptr,int key,int pos){
    ptr=(int*)realloc(ptr,(n+1)*sizeof(int));
    if(pos<1||pos>n+1){
        printf("invalid pos");
        return ;
        
    }
    for(int i=n;i>pos;i--){
        *(ptr+i)=*(ptr+(i-1));
        
    }
    *(ptr+pos-1)=key;
    n++;
}
void deletebypos(int* ptr,int pos){
    printf("deleted key is %d",*(ptr+(pos-1)));
    for(int i=pos-1;i<n-1;i++){
        *(ptr+i)=*(ptr+(i+1));
    }
    n--;
}


void insertbyorder(int* ptr,int key){
    ptr=(int*)realloc(ptr,(n+1)*sizeof(int));
    for(int i=0;i<n;i++){
        if(*(ptr+i)>key){
             pos=i+1;
            for(int i=n;i>pos;i++){
                *(ptr+i)=*(ptr+(i-1));
            }
            *(ptr+(pos-1))=key;
            break;
        }
    }
    *(ptr+(pos-1))=key;
    n++;
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
void searchbykey(int* ptr,int key){
    int flag=0;
    for(int i=0;i<n;i++){
            if(*(ptr+i)==key){
                flag=1;
                pos=i+1;
                break;
            }
    }
    if(flag==0){
        printf("%d not found",key);
        return;
    
    }
    if(flag ==1){
        printf("%d found at position %d",key,pos);
        return;
        
    }
    
}
void sort(int* ptr){
    int temp;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(*(ptr+j)>*(ptr+(j+1))){
             temp=*(ptr+j);
             *(ptr+j)=*(ptr+(j+1));
             *(ptr+(j+1))=temp;
            }
        }
    }
}
void reverse(int* ptr){
    int left=0; 
    int right=n-1;
    int temp;
    while(left<right){
        temp=*(ptr+left);
        *(ptr+left)=*(ptr+right);
        *(ptr+right)=temp;
        left++;
        right--;
    }
}
int main()
{
    int *ptr;
    int i;
    //int key,pos;
    printf("\nenter the number of elements: ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    read(ptr);
    display(ptr);
    printf("\nenter key and pos: ");
    scanf("%d %d",&key,&pos);
    insertbypos(ptr,pos,key);
    display(ptr);
    printf("\nEnter the position to be deleted: ");
    scanf("%d",&pos);
    deletebypos(ptr,pos);
    display(ptr);
    printf("\nenter the key to be inserted: ");
    scanf("%d",&key);
    insertbyorder(ptr,key);
    display(ptr);
    printf("\nenter the key to be deleted: ");
    scanf("%d",&key);
    deletebykey(ptr,key);
    display(ptr);
    printf("\nenter the key to be searched: ");
    scanf("%d",&key);
    searchbykey(ptr,key);
    printf("\n");
    display(ptr);
    sort(ptr);
    reverse(ptr);
    printf("\n");
    display(ptr);
}

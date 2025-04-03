#include<stdio.h>
#include<string.h>
int main()
{
  char a[20],b[20],c[20];
  printf("enter the first string:");
  scanf("%s",a);
  printf("enter the second string:");
  scanf("%s",b);
  int l1,l2;
  l1=strlen(a);
  l2=strlen(b);
  if(l1!=l2){
    printf("strings are not equal");
  }
  
  else{
    int i=0,flag=0;
  while((a[i]!='\0')){
  if(a[i]!=b[i]){
    flag=1;
    break;
  }
  i++;
  }
  if(flag==0){
    printf("strings are ==");
  }
  }
  return 0;
}
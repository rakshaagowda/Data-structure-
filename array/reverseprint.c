//print the elements of an array in   reverse order 
#include <stdio.h>

int main()
{
  int arr[5],i;
  for(i=0;i<5;i++)
  {
    scanf("%d",&arr[i]);
  }
  for(i=4;i>=0;i--)
  {
  
    printf("%d ",arr[i]);
  }   
}
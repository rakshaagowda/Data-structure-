//
#include <stdio.h>
#include <stdlib.h>
void reverse_elements(int arr[], int n){
  int temp;
  for(int i=0; i<n/2; i++){
    temp = arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1] = temp;
  }
}
int main(){
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements: ");
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);

}
reverse_elements(arr, n);
printf("Reversed array: "); 
for(int i=0; i<n; i++){
  printf("%d ", arr[i]);
}
printf("\n");
return 0;
}


#include <stdio.h>
#include <string.h>
void frequency(char str[],char ch){
 int  count=0;
  for(int i=0;i<strlen(str);i++){
    if(str[i]==ch){
      count++;
  }
  
  }
  printf("%c-%d",ch,count);

}
int main(){
  char ch, str[10];
  scanf("%[^\n]s",str);
  int len=strlen(str);
  for (int i=0;i<len;i++){
    ch=str[i];
    frequency(str,str[i]);
  }
  return 0;

}
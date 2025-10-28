#include <stdio.h>
#include <string.h>

int main() {
  char str[255];
  int i=0;
  char ch;
  printf("Enter a string: ");
  while ((ch=getchar()) != '\n') {str[i++]=ch;}
  str[i]='\0';

  for (int i=(int)strlen(str); i>=0; i--) {
    printf("%c", str[i]);
  }
  
  return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
  char str[255];
  printf("Enter a string: ");
  scanf("%[^\n]", str);

  for (int i=(int)strlen(str); i>=0; i--) {
    printf("%c", str[i]);
  }
  
  return 0;
}

#include <stdio.h>

int main() {
  char arr[255];
  int count = 0;
  printf("Enter your string: ");
  for (int i=0;i<255;i++) {
    scanf("%c", &arr[i]);
    if (arr[i]=='\n') {break;}
    count += 1;
  }
  
  printf("Reversed string: ");
  for (int i=count-1;i>=0;i--) {printf("%c", arr[i]);}

  return 0;
}

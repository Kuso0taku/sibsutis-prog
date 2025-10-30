#include <stdio.h>

int main() {
  unsigned short count=0;
  char ch;
  printf("Input smth here ('#' to exit):\n");
  while ((ch=getchar()) != '#') {
    if (ch=='.') {printf("!");count++;}
    else if (ch=='!') {printf("!!");count++;}
    else {putchar(ch);}
  }
  printf("\nReplaced %hu characters\n", count);
  
  return 0;
}

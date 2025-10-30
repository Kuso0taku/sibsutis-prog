#include <stdio.h>

int main() {
  unsigned short count=0;
  char ch;
  printf("Enter smth here ('#' to exit):\n");
  while ((ch=getchar()) != '#') {
    printf("'%c':%hu ", ch, ch);
    if (!(++count % 8)) {putchar('\n');}
  }
  
  return 0;
}

#include <stdio.h>

int main() {
  unsigned short count=0;
  char ch;
  printf("Input smth here ('#' to exit):\n");
  while ((ch=getchar()) != '#') {
    switch (ch) {
      case '.': printf("!");count++; break;
      case '!': printf("!!");count++;break;
      default: printf("%c", ch);}
  }
  printf("\nReplaced %hu characters\n", count);
  
  return 0;
}

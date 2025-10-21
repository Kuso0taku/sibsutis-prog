#include <stdio.h>

int main() {
  unsigned short count;
  char ch0,ch1;
  printf("Enter smth here ('#' to exti):\n");
  ch0=getchar();
  while ((ch0 != '#') && (ch1=getchar()) != '#') {
    if (ch0=='e' && ch1=='i') {count++;}
    ch0=ch1;
  }
  printf("The input has %hu \"ei\"\n", count);
  
  return 0;
}

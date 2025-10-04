#include <stdio.h>

void prnt(void) {
  printf("Улыбайся!");
}

int main(void) {
  for (int i=0;i<3;i++) {prnt();}
  printf("\n");
  for (int i=0;i<2;i++) {prnt();}
  printf("\n");
  prnt();
  printf("\n");
  return 0;
}

#include <stdio.h>

void jolly(void) {
  printf("Он веселый молодец!\n");
}

void deny(void) {
  printf("Никто не может это отрицать!\n");
}

int main(void) {
  for (int i=0; i<3;i++) {jolly();}
  deny();
  return 0;
}

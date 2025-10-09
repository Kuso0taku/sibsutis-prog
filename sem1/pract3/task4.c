#include <stdio.h>

int main() {
  char name[255];
  printf("Enter your name: ");
  scanf("%s", name);

  float height;
  printf("Enter your height in cm: ");
  scanf("%f", &height);
  height /= 100;

  printf("%s, your height is %.2f meters\n", name, height);

  return 0;
}

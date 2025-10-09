#include <stdio.h>

int main() {
  float num;
  printf("Enter float num: ");
  scanf("%f", &num);
  printf("а) Your num is %f or %e\n", num, num);
  printf("б) Your num is %+f or %E\n", num, num);

  return 0;
}

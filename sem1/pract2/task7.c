#include <stdio.h>

int main() {
  int cm;
  printf("Enter your height in cm: ");
  scanf("%d", &cm);

  float inchs = cm/2.54;
  printf("Your height in inches: %.2f\n", inchs);

  return 0;
}

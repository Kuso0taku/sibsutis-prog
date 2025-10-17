#include <stdio.h>

double sqr(double num) {
  return num*num;
}

int main() {
  double num;
  printf("Enter double num: ");
  scanf("%lf", &num);
  printf("Square of this num: %lf\n", sqrt(num));
  
  return 0;
}

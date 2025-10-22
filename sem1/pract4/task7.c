#include <stdio.h>

double pow(double num) {
  return num*num*num;
}

int main() {
  double num;
  printf("Enter double num: ");
  scanf("%lf", &num);
  printf("Square of this num: %lf\n", pow(num));
  
  return 0;
}

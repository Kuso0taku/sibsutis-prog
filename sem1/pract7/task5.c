#include <stdio.h>

void larger_of(double *x, double *y) {
  if (*x == *y) return;
  *x = (*x > *y) ? *x : *y;
  *y = *x;
}

int main() {
  double x, y;
  int code;
  do {
    printf("Enter two double numbers (q to exit): ");
    code = scanf("%lf%lf", &x, &y);
    if (code == 2) {larger_of(&x, &y);printf("x=%lf, y=%lf\n", x, y);}
  } while (code == 2);
  printf("Done.\n");
  
  return 0;
}

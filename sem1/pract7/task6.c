#include <stdio.h>

double Max(double x, double y, double z) {
  double max = x;
  if (y > max) max=y;
  if (z > max) max=z;
  return max;
}

double Min(double x, double y, double z) {
  double min = x;
  if (y < min) min=y;
  if (z < min) min=z;
  return min;
}

void replacer(double *x, double *y, double *z) {
  double max = Max(*x, *y, *z), min = Min(*x, *y, *z), mid=*z;
  if (*x != min && *x != max) mid=*x;
  else if (*y != min && *y != max) mid=*y;
  *x=min,*y=mid,*z=max;
}

int main() {
  double x, y, z;
  int code;
  do {
    printf("Enter three double numbers (q to exit): ");
    code = scanf("%lf%lf%lf", &x, &y, &z);
    if (code == 3) {replacer(&x, &y, &z);printf("x=%lf, y=%lf, z=%lf\n", 
                                                x, y, z);}
  } while (code == 3);
  printf("Done.\n");
  
  return 0;
}

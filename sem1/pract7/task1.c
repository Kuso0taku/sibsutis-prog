#include <stdio.h>

double min(double x, double y) {
  return (x<y) ? x : y;
}

int main() {
  int code;
  double x, y;
  do {
    printf("Enter two double values: ");
    code = scanf("%lf%lf", &x, &y);
    if (code==2) {printf("Minimal value of %lf and %lf is %lf\n",
                         x, y, min(x, y));}
  } while (code == 2);
  printf("Oops! Wrong input!\n");
  
  return 0;
}

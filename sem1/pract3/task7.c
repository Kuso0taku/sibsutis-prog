#include <stdio.h>
#include <float.h> // for FLT_DIG, DBL_DIG

int main() {
  double dbl = 1.0/3.0;
  float flt = 1.0/3.0;
  printf("1.0/3.0:\n");
  printf("double: %.4lf\tfloat: %.4f\n", dbl, flt);
  printf("double: %.12lf\tfloat: %.12f\n", dbl, flt);
  printf("double: %.16lf\tfloat: %.16f\n", dbl, flt);
  
  printf("\nDBL_DIG: %d\tFLT_DIG: %d\n\n", DBL_DIG, FLT_DIG);
  
  double dbl_ = 1.0/0.3;
  float flt_ = 1.0/0.3;
  printf("1.0/0.3\n");
  printf("double: %.16lf\tfloat: %.16f\n", dbl_, flt_);

  return 0;
}

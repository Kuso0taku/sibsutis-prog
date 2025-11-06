#include <stdio.h>
#include <stdlib.h> // atoi, atof
#include <math.h> // pow

int main(int argc, char **argv) {
  double a = atof(argv[1]);
  int n = atoi(argv[2]);
  printf("(%.2lf)^%d = %.2lf\n", a, n, pow(a, n));

  return 0;
}

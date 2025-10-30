#include <stdio.h>

double avg_harmonic(double a, double b) {
  if (a==0 || b==0) {return -1;} // zero division
  return 2/(1/a + 1/b);
}

int main() {
  double a, b;
  int code;
  do {
    printf("Enter two double numbers (q to exit): ");
    code = scanf("%lf%lf", &a, &b);
    if (code == 2) printf("Average harmonic value: %lf\n", 
                          avg_harmonic(a, b));
  } while (code == 2);
  printf("Done.\n");

  return 0;
}

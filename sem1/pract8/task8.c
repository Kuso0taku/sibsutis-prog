#include <stdio.h>

void copy_ptr(double target[], double source[], int n) {
  for (int i=0; i<n; i++) *target++ = *source++;
}

void print(double arr[], int n) {
  double *ptr = arr;
  printf("{");
  for (int i=0; i<n; i++) {
    printf("%.1f", *ptr++);
    if (i<n-1) printf(", ");
  }
  printf("}\n");
}

int main() {
  double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
  double target[3];
  
  copy_ptr(target, source+2, 3);
  
  printf("source = "); print(source, 7);
  printf("target = "); print(target, 3);

  return 0;
}

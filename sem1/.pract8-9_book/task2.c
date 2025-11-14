#include <stdio.h>

void copy_arr(double target[], double source[], int n) {
  for (int i=0; i<n; i++) target[i]=source[i];
}

void copy_ptr(double target[], double source[], int n) {
  for (int i=0; i<n; i++) *target++ = *source++;
}

void copy_ptrs(double target[], double source[], double *pptr) {
  for (; source<pptr; target++, source++) {*target = *source;}
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
  double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double target1[5];
  double target2[5];
  double target3[5];
  
  copy_arr(target1, source, 5);
  copy_ptr(target2, source, 5);
  copy_ptrs(target3, source, source + 5);
  
  printf("source = "); print(source, 5);
  printf("target1 = "); print(target1, 5);
  printf("target2 = "); print(target2, 5);
  printf("target3 = "); print(target3, 5);

  return 0;
}

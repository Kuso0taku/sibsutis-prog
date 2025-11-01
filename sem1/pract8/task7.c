#include <stdio.h>

void copy_ptr(double target[], double source[], int n) {
  for (int i=0; i<n; i++) *target++ = *source++;
}

void print_arr(int rows, int cols, double arr[rows][cols]) {
  double *ptr = &arr[0][0];
  printf("{\n");
  for (int i=0; i<rows; i++) {
    printf("  {");
    for (int j=0; j<cols; j++, ptr++) {
      printf("%.2lf", *ptr);
      if (j<cols-1) printf(", ");
    }
    printf("}");
    if (i<rows-1) printf(",\n");
  }
  printf("\n}\n");
}

int main() {
  int rows, cols;
  printf("Enter sizes of the array (rows and cols): ");
  while (!(scanf("%d%d", &rows, &cols)) || rows <= 0 || cols <= 0) 
    printf("Wrong input! Enter two positive ints: ");
  
  double arr[rows][cols];
  double tar[rows][cols];
  double *ptr = &arr[0][0];

  for (int i=0; i<rows; i++) {
    printf("Enter every element of the %dth array: ", i+1);
    for (int j=0; j<cols; j++, ptr++) scanf("%lf", ptr);
    copy_ptr(tar[i], arr[i], cols);
  }

  printf("Source array:\n"); print_arr(rows, cols, arr);
  printf("Target array:\n"); print_arr(rows, cols, tar);

  return 0;
}

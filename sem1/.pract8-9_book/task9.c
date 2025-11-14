#include <stdio.h>

void copy_ptr(int rows, int cols, 
              double target[rows][cols], double source[rows][cols]) {
  double *ptr_src = &source[0][0];
  double *ptr_tar = &target[0][0];
  for (int i=0; i<rows*cols; i++) *ptr_tar++ = *ptr_src++;
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
  int rows=3, cols=5;
  double arr[3][5] = {
    {1.1, 2.2, 3.3, 4.4, 5.5},
    {5.5, 1.1, 2.2, 3.3, 4.4},
    {4.4, 5.5, 1.1, 2.2, 3.3}
  };
  double tar[rows][cols];
  
  copy_ptr(rows, cols, tar, arr);

  printf("Source array:\n"); print_arr(rows, cols, arr);
  printf("Target array:\n"); print_arr(rows, cols, tar);

  return 0;
}

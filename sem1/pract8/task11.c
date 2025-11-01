#include <stdio.h>
#define ROWS 3
#define COLS 5

void modify_arr(int rows, int cols, double arr[rows][cols]) {
  double *ptr = &arr[0][0];
  for (int i=0; i<rows*cols; i++, ptr++) *ptr = 2*(*ptr);
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
  printf("The array will be 3x5.\n");

  double arr[ROWS][COLS];
  double *ptr = &arr[0][0];

  for (int i=0; i<ROWS; i++) {
    printf("Enter every element of the %dth array: ", i+1);
    for (int j=0; j<COLS; j++, ptr++) scanf("%lf", ptr);
  }

  printf("The array:\n"); print_arr(ROWS, COLS, arr);
  modify_arr(ROWS, COLS, arr);
  printf("The array has modified\n");
  printf("The array now:\n"); print_arr(ROWS, COLS, arr);

  return 0;
}

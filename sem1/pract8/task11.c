#include <stdio.h>
#define ROWS 3
#define COLS 5

void modify_arr(int rows, int cols, int arr[rows][cols]) {
  int *ptr = &arr[0][0];
  for (int i=0; i<rows*cols; i++, ptr++) *ptr = 2*(*ptr);
}

void print_arr(int rows, int cols, int arr[rows][cols]) {
  int *ptr = &arr[0][0];
  printf("{\n");
  for (int i=0; i<rows; i++) {
    printf("  {");
    for (int j=0; j<cols; j++, ptr++) {
      printf("%d", *ptr);
      if (j<cols-1) printf(", ");
    }
    printf("}");
    if (i<rows-1) printf(",\n");
  }
  printf("\n}\n");
}

int main() {
  printf("The array will be 3x5.\n");

  int arr[ROWS][COLS];
  int *ptr = &arr[0][0];

  for (int i=0; i<ROWS; i++) {
    printf("Enter every element of the %dth array: ", i+1);
    for (int j=0; j<COLS; j++, ptr++) scanf("%d", ptr);
  }

  printf("The array:\n"); print_arr(ROWS, COLS, arr);
  modify_arr(ROWS, COLS, arr);
  printf("The array has modified\n");
  printf("The array now:\n"); print_arr(ROWS, COLS, arr);

  return 0;
}

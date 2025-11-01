#include <stdio.h>
#define ROWS 3
#define COLS 5

double Sub_avg(double arr[]) {
  double sum=0;
  double *ptr = arr;
  for (int i=0; i<COLS; i++, ptr++) sum += *ptr;
  return sum/COLS;
}

double Avg(double arr[ROWS][COLS]) {
  double sum=0;
  double *ptr = &arr[0][0];
  for (int i=0; i<ROWS*COLS; i++, ptr++) sum += *ptr;
  return sum/(ROWS*COLS);
}

double Max(double arr[ROWS][COLS]) {
  double *ptr = &arr[0][0];
  double m = *ptr;
  for (int i=0; i<ROWS*COLS; i++, ptr++) m = (m>=*ptr) ? m : *ptr;
  return m;
}

void print_arr(double arr[ROWS][COLS]) {
  double *ptr = &arr[0][0];
  printf("{\n");
  for (int i=0; i<ROWS; i++) {
    printf("  {");
    for (int j=0; j<COLS; j++, ptr++) {
      printf("%.2lf", *ptr);
      if (j<COLS-1) printf(", ");
    }
    printf("}");
    if (i<ROWS-1) printf(",\n");
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

  printf("\na) The array:\n"); print_arr(arr);

  printf("b) Average values:\n");
  for (int i=0; i<ROWS; i++) 
    printf("\tavg for %dth array: %.2lf\n", i+1, Sub_avg(arr[i]));

  printf("c) Avg for all values: %.2lf\n", Avg(arr));

  printf("d) Max value out of %d elements: %.2lf\n", 
         ROWS*COLS, Max(arr));

  return 0;
}

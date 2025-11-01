#include <stdio.h>
#define ROWS 3
#define COLS 5

double Sub_avg(double arr[], int n) {
  double sum=0;
  double *ptr = arr;
  for (int i=0; i<n; i++, ptr++) sum += *ptr;
  return sum/n;
}

double Avg(int rows, int cols, double arr[rows][cols]) {
  double sum=0;
  double *ptr = &arr[0][0];
  for (int i=0; i<rows*cols; i++, ptr++) sum += *ptr;
  return sum/(rows*cols);
}

double Max(int rows, int cols, double arr[rows][cols]) {
  double *ptr = &arr[0][0];
  double m = *ptr;
  for (int i=0; i<rows*cols; i++, ptr++) m = (m>=*ptr) ? m : *ptr;
  return m;
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
  printf("Enter sizes of the araays (rows 'n cols): ");
  while (!(scanf("%d%d", &rows, &cols)) || rows <= 0 || cols <= 0) {
    printf("Wrong input! Enter positive int: ");
    while (getchar() != '\n');} // clearing buffer

  double arr[rows][cols];
  double *ptr = &arr[0][0];

  for (int i=0; i<rows; i++) {
    printf("Enter every element of the %dth array: ", i+1);
    for (int j=0; j<cols; j++, ptr++) scanf("%lf", ptr);
  }

  printf("\na) The array:\n"); print_arr(rows, cols, arr);

  printf("b) Average values:\n");
  for (int i=0; i<ROWS; i++) 
    printf("\tavg for %dth array: %.2lf\n", i+1, Sub_avg(arr[i], cols));

  printf("c) Avg for all values: %.2lf\n", Avg(rows, cols, arr));

  printf("d) Max value out of %d elements: %.2lf\n", 
         rows*cols, Max(rows, cols, arr));

  return 0;
}

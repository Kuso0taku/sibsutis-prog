#include <stdio.h>

void copy_ptr(double array1[], double array2[], double target[], int n) {
  for (int i=0; i<n; i++, array1++, array2++) *target++ = *array1 + *array2;
}

void print_arr(double arr[], int n) {
  printf("{");
  for (int i=0; i<n; i++, arr++) {
    printf("%.2lf", *arr);
    if (i<n-1) printf(", ");
  }
  printf("}\n");
}

int main() {
  int size;
  printf("Enter the size of the arrays (one number for both): ");
  while (!(scanf("%d", &size)) || size <= 0) {
    printf("Wrong input! Enter two positive ints: ");
    while (getchar() != '\n');} // clearing buffer
  
  double arr1[size];
  double arr2[size];
  double tar[size];
  double *ptr;

  for (int i=0; i<2; i++) {
    printf("Enter every element of the %dth array: ", i+1);
    ptr = (i==0) ? arr1 : arr2;
    for (int j=0; j<size; j++, ptr++) scanf("%lf", ptr);
  }
  
  copy_ptr(arr1, arr2, tar, size);

  printf("First array: "); print_arr(arr1, size);
  printf("Second array: "); print_arr(arr2, size);
  printf("Target array: "); print_arr(tar, size);

  return 0;
}

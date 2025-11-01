#include <stdio.h>

void reverse(double arr[], int n) {
  double temp;
  for (int i=0; i<n/2; i++) {
    temp = arr[i];
    arr[i]=arr[n-1-i];
    arr[n-1-i]=temp;
  }
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
  printf("Enter the size of the array: ");
  while (!(scanf("%d", &size)) || size <= 0) 
    printf("Wrong input! Enter positive int: ");

  printf("Enter every element of the array: ");
  double arr[size];
  double *ptr = &arr[0];
  for (int i=0; i<size; i++, ptr++) scanf("%lf", ptr);
  
  printf("Your array: "); print_arr(arr, size);
  reverse(arr, size);
  printf("Reversed: "); print_arr(arr, size);

  return 0;
}

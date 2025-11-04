#include <stdio.h>

double dif_max_min(double arr[], int n) {
  double mi=*arr, ma=*arr;
  for (int i=0; i<n; i++, arr++) {
    ma = (ma>=*arr) ? ma : *arr;
    mi = (mi<=*arr) ? mi : *arr;
  }
  return ma-mi;
}

int main() {
  int size;
  printf("Enter the size of the array: ");
  while (!(scanf("%d", &size)) || size <= 0) {
    printf("Wrong input! Enter positive int: ");
    while (getchar() != '\n');} // clearing buffer

  printf("Enter every element of the array: ");
  double arr[size];
  double *ptr = &arr[0];
  for (int i=0; i<size; i++, ptr++) scanf("%lf", ptr);
  
  printf("The difference of max and min elements of your array: %lf\n", 
         dif_max_min(arr, size));

  return 0;
}

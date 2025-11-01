#include <stdio.h>

int max(int arr[], int n) {
  int m=*arr;
  for (int i=0; i<n; i++, arr++) m = (m>=*arr) ? m : *arr;
  return m;
}

int main() {
  int size;
  printf("Enter the size of the array: ");
  while (!(scanf("%d", &size)) || size <= 0) 
    printf("Wrong input! Enter positive int: ");

  printf("Enter every element of the array: ");
  int arr[size];
  int *ptr = &arr[0];
  for (int i=0; i<size; i++, ptr++) scanf("%d", ptr);
  
  printf("The max element of your array: %d\n", max(arr, size));

  return 0;
}

#include <stdio.h>

int max_i(double arr[], int n) {
  int m_i=0;
  for (int i=0; i<n; i++) m_i = (arr[m_i] >= arr[i]) ? m_i : i;
  return m_i;
}

int main() {
  int size;
  printf("Enter the size of the array: ");
  while (!(scanf("%d", &size)) || size <= 0) {
    printf("Wrong input! Enter positive int: ");
    while (getchar() != '\n');} // clearing buffer

  printf("Enter every double element of the array: ");
  double arr[size];
  double *ptr = &arr[0];
  for (int i=0; i<size; i++, ptr++) scanf("%lf", ptr);
  
  printf("The max element index of your array: %d\n", max_i(arr, size));

  return 0;
}

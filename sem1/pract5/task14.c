#include <stdio.h>

int main() {
  double arr1[8];
  double arr2[8];
  double sum=0;
  printf("Enter 8 double elements of array: ");
  for (int i=0; i<8; i++) {
    scanf("%lf", &arr1[i]);
    sum += arr1[i];
    arr2[i]=sum;
  }
  printf("Result of program:\n");
  for (int i=0; i<8; i++) {printf("%-10lf ", arr1[i]);}
  printf("\n");
  for (int i=0; i<8; i++) {printf("%-10lf ", arr2[i]);}
  printf("\n");
  
  return 0;
}

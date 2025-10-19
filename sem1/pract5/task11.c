#include <stdio.h>

int main() {
  int arr[8];
  printf("Enter 8 int numbers: ");
  for (int i=0; i<8; i++) {scanf("%d", &arr[i]);}
  printf("Your numbers: ");
  for (int i=7; i>=0; i--) {printf("%d ", arr[i]);}
  
  return 0;
}

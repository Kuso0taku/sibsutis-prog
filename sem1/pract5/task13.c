#include <stdio.h>

int main() {
  int arr[8];
  for (int i=0;i<8;i++) {
    int pow = 2;
    for (int j=2; j<=i+1;j++) {pow *= 2;}
    arr[i]=pow;
  }
  int i=0;
  do {
    printf("%d ", arr[i++]);
  } while (i<8);
  
  return 0;
}

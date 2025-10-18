#include <stdio.h>

int main() {
  int n, i=0;
  printf("Enter your num: ");
  scanf("%d", &n);
  printf("Nums: ");
  while (i++ <= 10) {printf("%d ", n++);} ;

  return 0;
}

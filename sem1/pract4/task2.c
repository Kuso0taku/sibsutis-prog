#include <stdio.h>

int main() {
  int n;
  printf("Enter your num: ");
  scanf("%d", &n);
  printf("Nums: ");
  for (int i=0;i<=10;i++) {
    printf("%d ",n+i);
  }

  return 0;
}

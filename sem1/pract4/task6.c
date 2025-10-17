#include <stdio.h>

int main() {
  int count=0;
  int sum=0;
  int n;
  printf("Enter number of times to sum: ");
  scanf("%d", &n);
  while (count++ < n) {sum = count*count;}
  printf("sum = %d\n", sum);

  return 0;
}

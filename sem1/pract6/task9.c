#include <stdio.h>
#include <math.h> // for sqrt

_Bool prime(int num) {
  if (num < 2) return 0;
  if (num == 2) return 1;
  if (num % 2 == 0) return 0;

  for (int i=3; i<=sqrt(num); i+=2) {
    if (num % i == 0) {return 0;}
  }
  return 1;
}

int main() {
  int num;
  printf("Enter a positive number: ");
  scanf("%d", &num);
  while (num <= 0) {printf("Positive number!!!\n"); scanf("%d", &num);}

  printf("All prime number <= %d:\n", num);
  for (int i=2; i<=num; i++) {
    if (prime(i)) printf("%d ", i);
  }

  return 0;
}

#include <stdio.h>

int main() {
  int n_even=0, n_odd=0, even_sum=0, odd_sum=0;
  int num;

  printf("Enter int numbers (0 to stop): ");
  scanf("%d", &num);
  while (num != 0) {
    if (num%2) {
      n_odd++; odd_sum += num;
    } else {n_even++; even_sum += num;}
    scanf("%d", &num);
  }
  printf("Number of even: %d\nAvg even: %d\n", n_even, even_sum/n_even);
  printf("Number of odd: %d\nAvg odd: %d\n", n_odd, odd_sum/n_odd);
  
  return 0;
}

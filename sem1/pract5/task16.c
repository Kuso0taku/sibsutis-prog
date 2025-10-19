#include <stdio.h>

int main() {
  int da_money=100, de_money=100;
  int years = 1;
  while (de_money <= da_money) {
    da_money += 100 * 10/100;
    de_money += de_money * 5/100;
    years++;
  }
  printf("After %d years Deira became richer than Daphne:\n", years);
  printf("Deira's balance: $%d\n", de_money);
  printf("Daphne's balance: $%d\n", da_money);
  
  return 0;
}

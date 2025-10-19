#include <stdio.h>

int main() {
  const int perc=8, award = 1'000'000, withdraw = 100'000;
  int years = 1;
  int balance = award;

  while (balance >= withdraw) {
    balance += balance * perc/100 - withdraw;
    years++;
  }
  printf("Your money'll be gone in %d years\n", ++years);
   
  return 0;
}

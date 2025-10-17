#include <stdio.h>

#define WEEK 7

int main() {
  int days;
  do {
    printf("Enter days: ");
    scanf("%d", &days);
    if (days > 0) {printf("%d days equals %d weeks and %d days\n", days, days/WEEK, days%WEEK);}
  } while (days > 0);

  return 0;
}

#include <stdio.h>

#define HOUR 60

int main() {
  int mins;
  do {
    printf("Enter minutes: ");
    scanf("%d", &mins);
    printf("Time is %dh %dm\n", mins/HOUR, mins%HOUR);
  } while (mins > 0);
  printf("Thanks for using my program!\n");

  return 0;
}

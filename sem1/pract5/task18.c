#include <stdio.h>
#define DANBAR 150

int main() {
  int friends = 5;
  int weeks = 0;
  while (friends < DANBAR) {
    weeks++;
    friends = (friends-weeks)*2;
  }
  printf("Wow! You've %d friends in %d weeks!\n", friends, weeks);
  
  return 0;
}
